
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    if (x <= z) {
        int ans = y + z, tm = 1;
        for (int i = 2; ; i ++) {
            if (ans >= n) {
                tm = i - 1;
                break;
            }   

            ans = ans / x * (y + z) + ans % x;  
        }

        cout << tm << '\n';
    } else {
        const int INF = n;
        int tm = 0, res = 0, pas = (n - z + y - 1) / y, ans = max(1LL, (n - z + y - 1) / y);
        for (int i = 2; i <= n; i ++) {
            if (res >= x) {
                res -= x;
            } else {
                int tt = (x - res + (i - 1) * y - 1) / ((i - 1) * y);
                res = res + tt * (i - 1) * y - x;
                tm = tm + tt; 
            }

            int need = n - i * z - res;
            int cur = (max (0LL, need) + (i * y) - 1) / (i * y) + tm;
            if (cur >= n) {
                break;
            }
            ans = min (ans, cur);

            pas = cur;
        }

        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}