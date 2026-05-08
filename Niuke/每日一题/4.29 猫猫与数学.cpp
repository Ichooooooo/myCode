
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int a, b; 
    cin >> a >> b;

    if (a < b) swap (a, b);
    int ch = a - b;

    if (ch == 1) {
        cout << -1 << '\n';
        return;
    }

    if (ch == 0 && a == 1) {
        cout << 1 << '\n';
    } else if ((ch == 0 && a != 0)|| (ch != 0 && (gcd (ch, a) > 1))) {
        cout << 0 << '\n';
    } else {
        int ok = 0, mn = -1;
        for (int i = 2; i * i <= ch; i ++) {
            if (ch % i == 0) {
                if (mn == -1) {
                    mn = i - a % i;
                    mn = min (mn, ch / i - a % (ch / i));
                }
                else {
                    mn = min (mn, i - a % i);
                    mn = min (mn, ch / i - (a % (ch / i)));
                }
            } 
        }

        // cerr << mn << '\n';
        if (mn == -1) {
            cout << ch - a % ch << '\n';
        } else {
            cout << mn << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}