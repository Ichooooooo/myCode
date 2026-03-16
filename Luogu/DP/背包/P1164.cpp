
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m; cin >> n >> m;
    vector <int> a (n);

    for (int & i : a) cin >> i;

    vector <int> dp (m + 1);
    dp[0] = 1;
    for (int i = 0; i < n; i ++) {
        for (int j = m; j >= a[i]; j --) {
            dp[j] += dp[j - a[i]];
            // cout << j << ' ' << dp[j] << '\n';
        }
    }

    cout << dp[m] << '\n';  
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}