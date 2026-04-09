
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;

    vector <int> a (2 * n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    vector <vector <int> > dp (2 * n + 1, vector <int> (2 * n + 1));

    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l <= 2 * n - 1 - len + 1; l ++) {
            int r = l + len - 1;
        
            for (int k = l; k <= r - 1; k ++) {
                dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= 2 * n - 1 - n + 1; i ++) {
        ans = max (ans, dp[i][i + n - 1]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}