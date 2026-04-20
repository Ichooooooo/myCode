
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

int qpow (int x, int y, int mod) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }

    return ans;
}

void ovo() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    for (int i = 0; i < m; i ++) {
        int a = qpow (2, n, mod) - 1;
        int b = qpow (2, n - 1, mod);
        int dif = (qpow (((a * b) % mod + b) % mod, m - i, mod)) * qpow(qpow (2, 2 * n, mod), i, mod) % mod * n % mod;
    }

    int eqt = qpow ((2, n), m, mod);

    ans = (ans + eqt) % mod;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}