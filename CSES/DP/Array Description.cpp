#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <vector <int> > dp (n + 1, vector <int> (m + 2));

    if (a[1] == 0) {
        for (int i = 1; i <= m; i ++) {
            dp[1][i] = 1;
        }
    } else {
        dp[1][a[1]] = 1;
    }

    for (int i = 2; i <= n; i ++) {
        if (a[i] != 0) {
            dp[i][a[i]] = ((dp[i - 1][a[i]] + dp[i - 1][a[i] - 1]) % mod + dp[i - 1][a[i] + 1]) % mod;
        } else {
            for (int j = 1; j <= m; j ++) {
                dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1]) % mod + dp[i - 1][j + 1]) % mod;
            }
        }
    }

    int mx = 0;
    for (int i = 1; i <= m; i ++) {
        mx = (mx + dp[n][i]) % mod;
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}