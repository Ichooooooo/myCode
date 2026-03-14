 
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

const int N = 1e6 + 10;
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

void ovo(){   
    int n, x, t;
    cin >> n >> x >> t;
    
    if ((n - x) == 0 && t == 0) cout << 1 << '\n';
    else if ((n - x) == 0 && t != 0) cout << 0 << '\n';
    else {
        int ans, rs = t + 1;
        int a, b;
        a = (rs + 1) / 2, b = rs / 2;
        ans = C(x - 1,a - 1) * C(n - x - 1,b - 1) % mod;
        a = rs / 2, b = (rs + 1) / 2;
        ans = (ans + (C(x - 1,a - 1) * C(n - x - 1,b - 1) % mod)) % mod;

        cout << ans << '\n';
    }
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    f[0] = 1, g[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }

    while(_--)  ovo();  return 0;
}