
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <array<int, 2>> a (n);
    vector <int> xx (n), yy (n);

    for (int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
        xx[i] = a[i][0];
        yy[i] = a[i][1];
    }

    ranges :: sort (xx);
    ranges :: sort (yy);
    
    int x, y;
    if (n & 1) {
        x = xx[(n + 1) / 2 - 1];
        y = yy[(n + 1) / 2 - 1]; 
    } else {
        x = (xx[n / 2 - 1] + xx[(n + 1) / 2 - 1]) / 2;
        y = (yy[n / 2 - 1] + yy[(n + 1) / 2 - 1]) / 2;
    }

    auto check = [&](int x, int y) -> int {
        int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
        for (int i = 0; i < n; i ++) {
            auto [xx, yy] = a[i];
            xx -= x;
            yy -= y;
            
            if (xx >= 0 && yy >= 0) c1 ++;
            else if (xx >= 0 && yy < 0) c2 ++;
            else if (xx < 0 && yy >= 0) c3 ++;
            else c4 ++;
            
        }

        // return max (c1, max(c2, max (c3, c4)));
        return min ({c1, c2, c3, c4});
    };

    int ansx, ansy, mx = -1;
    for (int i = -10; i <= 10; i ++) {
        for (int j = -10; j <= 10; j ++) {
            int xx = x + i;
            int yy = y + j;
            int an = check (xx, yy);
            // cout << xx << ' ' << yy << ' ' << an << '\n';
            if (mx < an) {
                ansx = xx;
                ansy = yy;
                mx = an;
            }
        }
    }

    cout << ansx << ' ' << ansy << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}