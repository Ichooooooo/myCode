
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
// const int mod = 1e9 + 7;
using i128 = __int128;

i128 qpow (i128 x, i128 y, i128 mod) {
    i128 ans = 1;
    while (y) {
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }

    return ans;
}

void ovo() {
    int s, w, v, p, mod;
    cin >> s >> v >> w >> p >> mod;

    int nm = w * p;
    int ans = i128(qpow (s, nm, mod) * qpow (v, nm, mod)) % mod;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}