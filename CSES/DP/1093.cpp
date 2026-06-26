
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 2e5;
int dp[N];

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

int inv (int x) {
    return qpow (x, mod - 2);
}

void ovo() {
    int n; cin >> n;

    int m = n * (1 + n) / 2;
    if (m & 1) {
        cout << 0 << '\n';
        return;
    }
    m /= 2;
    dp[0] = 1;
    
    for (int i = 1; i <= n; i ++) {
        // cerr << "i : " << i << '\n';
        for (int j = m; j >= i; j --) {
            dp[j] = (dp[j] + dp[j - i]) % mod;          
            
            // cerr << "j : " << j << ' ' << dp[j] << '\n';
        }
    }

    cout << dp[m] * inv(2) % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}