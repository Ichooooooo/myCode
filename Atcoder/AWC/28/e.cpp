
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

void ovo() {
    int n, k; cin >> n >> k;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    vector <int> b (k + 1), dp (k + 1);
    for (int i = 1; i <= k; i ++) cin >> b[i];

    dp[0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = k; j >= 1; j --) { 
            if (a[i] == b[j]) dp[j] = (dp[j] + dp[j - 1]) % mod;
            // cerr << i << ' ' << j << ' ' << dp[j] << '\n';
        }
    }

    cout << dp[k] << '\n';          
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}