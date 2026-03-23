
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
using i128 = __int128;

void ovo() {
    int a, b, c, d, T;
    cin >> a >> b >> c >> d >> T;
    int n, m;
    cin >> m >> n;

    i128 A = -1 * (i128)n * (i128)m * (i128)d; 
    i128 B = (i128)m * (i128)c * (i128)d - (i128)(a - b) * (i128)n * (i128)d + (i128)n * (i128)m * (i128)d * (i128)T;
    i128 C = (i128)(a - b) * (i128)c * (i128)d + (i128)n * (i128)d * (i128)(a - b) * (i128)T;

    if (A == 0) {
        if (B > 0) cout << T << '\n';
        else cout << 0 << '\n';
        return;
    }

    i128 delta = B * B - 4 * A * C;
    i128 zhou = -1 * B / (2 * A);
    
    // cout << A << ' ' << B << ' ' << C << '\n';
    if (delta <= 0) {
        cout << 0 << '\n';
    } else {
        if (T <= zhou) {
            i128 t = A * (i128)T * (i128)T + B * (i128)T + C;
            if (t < 0) {
                cout << 0 << '\n';
            } else {
                cout << T << '\n';
            }
        } else if (zhou <= 0) {
            cout << 0 << '\n';
        } else {
            i128 ans;
            int anp;
            for (int i = 2; i >= -2; i --) {
                i128 x = i + zhou;
                i128 t = A * (i128)x * (i128)x + B * (i128)x + C;
                if (i == 2) {
                    ans = t;
                    anp = x;
                }
                if (t >= ans) {
                    ans = t;
                    anp = x;
                }
            }

            if (ans > 0) {
                cout << anp << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}