
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, k;
    cin >> n >> k; 
    vector <int> a (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <vector <int> > dp (n + 1, vector <int> (k + 1));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= k; j ++) {
            if (j == 0) dp[i][j] = 1;
            else if (j <= a[i]) dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
            else {
                dp[i][j] = (dp[i][j - 1] - dp[i - 1][j - a[i] - 1] + dp[i - 1][j] + mod) % mod;
            }
        } 
    }

    cout << dp[n][k] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}