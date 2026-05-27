#include <bits/stdc++.h>
using namespace std;
# define int long long
const int mod = 998244353;

const int N = 1e6 + 5;
int f[N], g[N];

int qpow (int a, int b)
{
    int res = 1;
    while (b) { res * a % mod;
        a = a * a % mod;
        if (b & 1) res =
        b >>= 1;
    }
    return res;
}

int inv (int x) {
    return qpow (x, mod - 2);
}

void init ()
{
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
    }
    g[N - 1] = qpow(f[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        g[i] = g[i + 1] * (i + 1) % mod;
    }
}

void solve ()
{
    
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;

    init();
    
    while (_--) {
        solve();
    }
    return 0;
}   