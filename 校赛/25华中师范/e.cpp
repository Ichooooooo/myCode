
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

const int N = 2e6 + 10;
int f[N];

int qpow (int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = (ans * x) % mod;
        x = x * x % mod;
        y >>= 1; 
    }

    return ans;
}

int inv (int x) {
    return qpow (x, mod - 2);
}

void init () {
    f[1] = 0, f[2] = 1;
    for (int i = 3; i < N; i ++) {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % mod;
    }
}

void ovo() {
    int n; cin >> n;
    // cerr << f[n - 1];
    cout << (f[n] * inv(qpow(n - 1, n))) % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    init();
    while (_--) ovo();
}