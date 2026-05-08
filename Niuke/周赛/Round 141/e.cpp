
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;

    if (n < 2 * m || n > m * (m + 1) / 2 + 1) {
        cout << "NO" << '\n';
    } else {

        int mx = -1;
        for (int i = m; i >= 1; i --) {
            int t = i * (i + 1) / 2 + 1;
            
            if (t > n) continue;

            // cerr << "i : " << i << "t : " << t << '\n';

            if ((n - t) % 2 == 0 && i + (n - t) / 2 == m) {
                mx = max (mx, i);
                break;
            }
        }

        // cerr << "max : " << mx << '\n';
        if (mx == -1)  {
            cout << "NO" << '\n';
            return;
        }

        cout << "YES" << '\n';
        int ch = (n - mx * (mx + 1) / 2 - 1) / 2;
        int now = 2;

        cerr << "ch : " << ch << '\n';

        for (int i = 1; i <= mx; i ++) {
            cout << 1 << ' ' << now << '\n';
            for (int j = now; j <= now + i - 2; j ++) {
                cout << j << ' ' << j + 1 << '\n';
            }
            now = now + i;
        }

        for (int i = 1; i <= ch; i ++) {
            cout << now -2 << ' ' << now << '\n';
            cout << now << ' ' << now + 1 << '\n';
            now += 2;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}