#include <bits/stdc++.h>
using namespace std;
#define int long long
#define arr3 array <int, 3> 
#define arr2 array <int, 2> 

void solve ()
{
    int n, m, k;
    cin >> n >> m >> k;
    
    map <arr2, int> amp;
    for (int i = 0; i < k; i ++) {
        int x, y, z; 
        cin >>x >> y >> z;
        amp[{x, y}] = z;
    }

    const int INF = 1e18;
    int ans = INF;
    auto dfs = [&] (auto self, map <arr2, int> & mp, int an) -> void {

        cerr << "an : " << an << '\n';

        if (mp.empty()) {
            ans = min (ans, an);
            // cerr << "an : " << an << '\n';
            return;
        }

        // cerr << "what ?" << '\n';
        int mx = 0;
        for (auto & [u, v] : mp) {

            int x = u[0], y = u[1];
            int z = v;

            // cerr << "mp : " << x << ' ' << y << ' ' << z << '\n';

            for (int i = -1; i <= 1; i ++) {
                for (int j = -1; j <= 1; j ++) {
                    if (abs (i) + abs (j) > 1) continue;
                    int xx = x + i;
                    int yy = y + j;
                    

                    // cerr << "xy : " << xx << ' ' << yy << '\n';

                    // cerr << "nm : " << n << ' ' << m << '\n';
                    if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                    // cerr << "xy : " << xx << ' ' << yy << '\n';

                    int cnt = 0;
                    for (int k = -1; k <= 1; k ++) {
                        for (int z = -1; z <= 1; z ++) {
                            if (abs (k) + abs (z) > 1) continue;
                            int xxx = xx + k;
                            int yyy = yy + z;
                            
                            if (mp.find({xxx, yyy}) != mp.end()) {
                                cnt++;
                            }
                        }
                    }

                    mx = max (mx, cnt);
                }
            }
        }

        // cerr << "mx : " << mx << '\n';

        for (auto & [u, v] : mp) {

            int x = u[0], y = u[1];
            int z = v;

            // cerr << "xy : " << x << ' ' << y << '\n';

            for (int i = -1; i <= 1; i ++) {
                for (int j = -1; j <= 1; j ++) {
                    if (abs (i) + abs (j) > 1) continue;
                    int xx = x + i;
                    int yy = y + j;
                    if (xx < 1 || xx > n || yy < 1 || yy > m) continue;

                    int cnt = 0, mn = 4;
                    for (int k = -1; k <= 1; k ++) {
                        for (int z = -1; z <= 1; z ++) {
                            if (abs (k) + abs (z) > 1) continue;
                            int xxx = xx + k;
                            int yyy = yy + z;
                            
                            if (xxx < 1 || xxx > n || yyy < 1 || yyy > m) continue;

                            if (mp.find({xxx, yyy}) != mp.end()) {
                                cnt++;
                                mn = min (mn, mp[{xxx, yyy}]);
                            }
                        }
                    }

                    // cerr << "xy : " << xx << ' ' << yy << " cnt : " << cnt << '\n';
                    
                    if (cnt == mx) {

                        // cerr << "xxyy : " << xx << ' ' << yy << '\n';

                        map <arr2, int> mmp = mp;
                        for (int k = -1; k <= 1; k ++) {
                            for (int z = -1; z <= 1; z ++) {
                                if (abs (k) + abs (z) > 1) continue;
                                int xxx = xx + k;
                                int yyy = yy + z;
                                
                                auto pos = mmp.begin();
                                if ((pos = mmp.find({xxx, yyy})) != mmp.end()) {
                                    auto [u, v] = *pos;
                                    mmp.erase (pos);

                                    int a = u[0], b = u[1], c = v;
                                    if (c - mn > 0)
                                    mmp[{a, b}] = c - mn;
                                }
                            }
                        }    
                        
                        self (self, mmp, an + mn);
                    }
                }
            }                       
        }
    };

    dfs (dfs, amp, 0);

    cout << ans << '\n';
}   

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}