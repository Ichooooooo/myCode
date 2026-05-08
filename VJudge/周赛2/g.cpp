#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;
const int N = 2e7;

int f[N + 5];
void init () {
    f[0] = 1;
    for (int i = 1; i <= N; i ++) {
        f[i] = (f[i - 1] * i % mod);
    }
}

int qpow (int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = (ans * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return ans;
}

int inv (int x) {
    return qpow (x, mod - 2);
}

void ovo() {
    int n = 0;
    vector <int> a (26);

    for (int i = 0; i < 26; i ++) {
        cin >> a[i];
        n += a[i];
    }

    int odd = (n + 1) / 2, jdd = n / 2;
    vector <int> dp (odd + 1);
    dp[0] = 1;
    
    for (int i = 0; i < 26; i ++) {
        for (int j = odd; j >= a[i]; j --) {
            if (a[i] == 0) continue;
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
        }
    }
    
    int ans = (dp[odd] * f[odd] % mod * f[jdd] % mod);
    for (int i = 0; i < 26; i ++) {
        ans = ans * inv (f[a[i]]) % mod;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;
    init();
    
    while (_--) {
        ovo ();
    }
}