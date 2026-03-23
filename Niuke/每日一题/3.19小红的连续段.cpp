// 1.分类讨论非常重要 2. 注意组合数初始化f[0], g[0] = 1;
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

const int N = 1010;
int f[N], g[N];

int qpow (int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1; 
    }

    return ans;
}

void init () {
    int x = 1;
    f[0] = g[0] = 1;
    for (int i = 1; i < N; i ++) {
        x = x * i % mod;
        f[i] = x;
        g[i] = qpow (x, mod - 2); 
    }
} 

int C (int n, int m) { //Cn, m
    if (m > n || m < 0) return 0;
    if (m == 0) return 1;
    return f[n] * g[n - m] % mod * g[m] % mod;
}

void ovo() {
    int x, y; cin >> x >> y;

    for (int i = 1; i <= x + y; i ++) {
        if (i == 1) {
            if (x != 0 && y != 0) cout << 0 << '\n';
            else cout << 1 << '\n';
            continue;
        }
        int ans = 0;
        int a1 = (i + 1) / 2, a2 = i / 2;
        ans = C(x - 1, a1 - 1) * C(y - 1, a2 - 1) % mod + C(x - 1, a2 - 1) * C(y - 1, a1 - 1) % mod;
        // cerr << x - 1 << ' ' << a1 - 1 << ' ' << C(x - 1, a1 - 1)  << '\n';
        cout << ans % mod << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;
    init();

    while (_--) ovo();
}