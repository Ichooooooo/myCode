
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

const int N = 2e5 + 10;
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

void init () {
    f[0] = 1, g[0] = 1;  // ve  ry important
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }
}

int C (int n, int m)
{
    if (m < 0 || m > n) return 0;

    return f[n] * g[m] % mod * g[n - m] % mod;
}

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    int cn1 = count(s.begin(), s.end(), 'j');
    int cn0 = count(s.begin(), s.end(), 'o');
    if (cn1 > (n + 1) / 2 || cn0 > n / 2) {
        cout << 0 << '\n';
        return;
    }

    int cn2 = n - cn1 - cn0;
    int ans = 1;
    
    ans = C((n + 1)/ 2, cn1) * f[cn1] % mod * C(n / 2, cn0) % mod * f[cn0] % mod * f[cn2] % mod;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;  
    // cin>>_;
    init();

    while (_--) ovo();
}