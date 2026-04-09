
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > a (n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    int t; cin >> t;
    const int MN = -1e10;
    vector <vector <int> > dp (n + 1, vector <int> (m + 1, MN)), vis (n + 1, vector <int> (m + 1, 1e10));

    for (int i = 0; i < t; i ++) {
        int u, v, x;
        cin >> u >> v >> x;
        vis[u][v] = x;
    }

    dp[1][1] = a[1][1];
    
    for (int i = 2; i <= m; i ++) {
        if (i - 1 >= vis[1][i])  {
            continue;
        }
        
        dp[1][i] = dp[1][i - 1] + a[1][i];
    }

    for (int j = 2; j <= n; j ++) {
        if (j - 1 >= vis[j][1]) {
            continue;            
        }

        dp[j][1] = dp[j - 1][1] + a[j][1];
    }

    for (int i = 2; i <= n; i ++) {
        for (int j = 2; j <= m; j ++) {
            if (i + j - 2 >= vis[i][j]) {
                continue;
            }
            dp[i][j] = max ({dp[i][j], dp[i - 1][j] + a[i][j], dp[i][j - 1] + a[i][j]});
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {

            ans = max (ans, dp[i][j]);
        }

        // cerr << '\n';
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}