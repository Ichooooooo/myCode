
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int a, b, c;
    cin >> a >> b >> c;

    if (c == 0) {
        cout << 1 << ' ' << 0 << ' ' << a << ' ' << b << '\n';
        return;
    }

    for (int i = 1; i * i <= abs (a); i ++) {
        if (a % i == 0) {
            for (int j = 1; j * j <= abs (c); j ++) {
                if (c % j == 0) {
                    int a1 = i;
                    int a2 = a / i;
                    int a3 = -1 * a1;
                    int a4 = -1 * a2;
                    int c1 = j;
                    int c2 = c / j;

                    if (a1 * c2 + a2 * c1 == b) {
                        cout << a1 << ' ' << c1 << ' ' << a2 << ' ' << c2 << '\n';
                        return;
                    }

                    if (a3 * c2 + a4 * c1 == b) {
                        cout << a3 << ' ' << c1 << ' ' << a4 << ' ' << c2 << '\n';
                        return;
                    }

                    if (a1 * c1 + a2 * c2 == b) {
                        cout << a1 << ' ' << c2 << ' ' << a2 << ' ' << c1 << '\n';
                        return;
                    }

                    if (a3 * c1 + a4 * c2 == b) {
                        cout << a3 << ' ' << c2 << ' ' << a4 << ' ' << c1 << '\n';
                        return;
                    }


                }
            }
        }
    }

    cout << "NO" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}