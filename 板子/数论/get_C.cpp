#include <bits/stdc++.h>
using namespace std;
# define int long long
const int mod = 998244353;

const int N = 1e5 + 10;
int f[N], g[N]; 

int qpow (int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int C (int n, int m)
{
    if (m < 0 || m > n) return 0;

    return f[n] * g[m] % mod * g[n - m] % mod;
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

    f[0] = 1, g[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }

    while (_--) {
        solve();
    }
    return 0;
}   