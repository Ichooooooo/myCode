
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <vector <int> > g (n + 1);

    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    vector <arr2> dp (n + 1);
    
    // 1 : 黑色
    auto dfs = [&](auto self, int u, int fa, int ok) -> int {
        if (dp[u][ok] != 0) return dp[u][ok];
        dp[u][ok] = 1;

        int ko = 0;        
        for (auto v : g[u]) {
            if (v == fa) continue;

            ko = 1;
            if (ok == 1) {
                dp[u][ok] = (dp[u][ok] * self (self, v, u, (1 ^ ok))) % mod;
            } else {
                dp[u][ok] = (dp[u][ok] * ((self (self, v, u, (1 ^ ok)) + self (self, v, u, ok)) % mod)) % mod ;
            }
        }

        return dp[u][ok];
    };

    cout << (dfs (dfs, 1, 0, 0) + dfs (dfs, 1, 0, 1)) % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}