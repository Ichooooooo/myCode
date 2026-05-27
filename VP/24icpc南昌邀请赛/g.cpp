
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m, q;
    cin >> n >> m >> q;

    vector <vector <arr2> > g (n + 1);
    for (int i = 0; i < m; i ++) {
        int u, v, d;
        cin >> u >> v >> d;
        g[u].push_back  ({v, d});
    }

    vector <vector <int> > dp (n + 1, vector <int> (40));
    
    for (int i = 1; i <= n; i ++) {
        dp[i][0] = 1;
    }

    const int INF = 1e9 + 5;
    for (int i = 1; i < 40; i ++) {
        for (int j = 1; j <= n; j ++) {
            for (auto [v, x] : g[j]) {
                dp[j][i] = max (dp[j][i], min(dp[v][i - 1] * x, INF));
            }
        }
    }

    // for (int i = 1; i <= n; i ++) {
    //     cerr << "i : " << '\n';
    //     for (int j = 1; j <= 5; j ++) {
    //         cerr << dp[i][j] << ' ';
    //     }
    // }

    while (q --) {
        int p, x; 
        cin >> p >> x;

        auto pos = upper_bound (dp[p].begin() + 1, dp[p].end(), x) - dp[p].begin();
        cout << pos << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}