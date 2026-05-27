
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;
    vector <vector <int> > g (n + 1);
    
    for (int i = 1; i <= m; i ++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }

    vector <int> dp (n + 1, -1);
    auto dfs = [&] (auto self, int u) -> int {
        if (dp[u] != -1) return dp[u];

        int ok = 0;
        for (auto v : g[u]) {
            ok = 1;
            if (dp[v] != -1) {
                dp[u] = max (dp[u], dp[v] + 1);
            } else {
                dp[v] = self (self, v);
                dp[u] = max (dp[u], dp[v] + 1);
            }
        }

        if (!ok) {
            dp[u] = 0;
        }

        return dp[u];
    };

    int mx = 0;
    for (int i = 1; i <= n; i ++) {
        mx = max (mx, dfs (dfs, i));
        // cerr << "i : " << i << ' ' << dp[i] << '\n';
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}