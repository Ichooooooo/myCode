#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int mod = 998244353;

i64 qpow (i64 a, i64 b) {
    i64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve ()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        i64 ans = qpow((m - i) * qpow(m - 1, mod - 2) % mod, n);
        cout << ans << ' ';
    }
}

int main ()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}