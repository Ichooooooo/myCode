
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int a, b, c, d, T;
    cin >> a >> b >> c >> d >> T;
    int n, m;
    cin >> m >> n;

    int A = -1 * n * m * d;
    int B = m * c * d - (a - b) * n * d + n * m * d * T;
    int C = (a - b) * c * d + n * d * (a - b) * T;

    if (A == 0) {
        if (B > 0) cout << T << '\n';
        else cout << 0 << '\n';
        return;
    }

    double delta = B * B - 4.0 * A * C;
    double zhou = -1.0 * B / (2.0 * A);

    // cout << A << ' ' << B << ' ' << C << '\n';
    if (delta <= 0) {
        cout << 0 << '\n';
    } else {
        if (T <= zhou) {
            cout << T << '\n';
        } else if (zhou <= 0) {
            cout << 0 << '\n';
        } else {
            int mn = zhou, mx = zhou + 1;
            double a1 = A * mn * mn * 1.0 + B * mn + C;
            double a2 = A * mx * mx * 1.0 + B * mx + C;
            int ans = 0;

            // cerr << a1 << ' ' << a2 << '\n';

            if (a1 < a2) ans = mx;
            else ans = mn;
            cout << ans << '\n'; 
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}