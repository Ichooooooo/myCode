
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;
const int INF = 1e16;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int mx = -INF, mn = INF;
    int cmx = 0, cmn = 0, ps = -1;

    if (a[1] != abs (a[1])) {
        mx = abs (a[1]), mn = a[1];
        cmx = 1, cmn = 1;
        ps = 2;
    } else {
        mx = a[1];
        cmx = 2;
        ps = 1;
    }
        // cerr << ps << '\n';
        // cerr << "mx : " << mx << ' ' << cmx << '\n';
        // cerr << "mn : " << mn << ' ' << cmn << '\n';
    for (int i = 2; i <= n; i ++) {
        if (ps == 1) {
            if (a[i] == abs (a[i])) {
                mx = mx + a[i];
                cmx = 2 * cmx % mod;
                ps = 1;
            } else {
                int x = mx + a[i];

                if (x >= 0) {
                    mx = x;
                    cmx = 2 * cmx % mod;
                    ps = 1;
                } else {
                    int old = cmx;
                    mx = -x;
                    mn = x;
                    cmx = old;
                    cmn = old;
                    ps = 2;
                }
            }
        } else {
            if (a[i] == abs (a[i])) {
                int t1 = abs (mx + a[i]);
                int t2 = abs (mn + a[i]);
                int t3 = mx + a[i];
                int t4 = mn + a[i];

                int tmx = max ({t1, t2, t3, t4});
                int tcmx = 0;

                if (tmx == t1) {
                    tcmx = cmx;
                }
                //唯一 
                if (tmx == t2) {
                    tcmx = (tcmx + cmn) % mod;
                }

                if (tmx == t3) {
                    tcmx = (tcmx + cmx) % mod;
                }

                if (tmx == t4) {
                    tcmx = (tcmx + cmn) % mod;
                }
                
                mx = tmx;
                cmx = tcmx;

                int tmn = mn + a[i];
                int tcmn = cmn;
                
                if (tmn == t2) {
                    tcmn = (tcmn + cmn) % mod;
                }

                mx = tmx;
                cmx = tcmx;
                mn = tmn;
                cmn = tcmn;
                ps = 2;
            } else {
                int t1 = abs (mx + a[i]);
                int t2 = abs (mn + a[i]);
                int t3 = mx + a[i];
                int t4 = mn + a[i];

                int tmx = max ({t1, t2, t3});
                int tcmx = 0;

                if (tmx == t1) {
                    tcmx = cmx;
                }
                //唯一 
                if (tmx == t2) {
                    tcmx = (tcmx + cmn) % mod;
                }

                if (tmx == t3) {
                    tcmx = (tcmx + cmx) % mod;
                }

                mx = tmx;
                cmx = tcmx;

                int tmn = mn + a[i];
                int tcmn = cmn;
                
                if (tmn == t2) {
                    tcmn = (tcmn + cmn) % mod;
                }

                mx = tmx;
                cmx = tcmx;
                mn = tmn;
                cmn = tcmn;
                ps = 2;
            }
        }

        // cerr << ps << '\n';
        // cerr << "mx : " << mx << ' ' << cmx << '\n';
        // cerr << "mn : " << mn << ' ' << cmn << '\n';
    }

    cout << cmx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}