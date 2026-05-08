
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 3005;
int cs[N][N];

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > g (n + 1);

    for (int i = 1; i <= n - m; i ++) {
        int k; cin >> k;
        for (int j = 1; j <= k; j ++) {
            int a, c;
            cin >> a >> c;
            g[i].push_back (a);
            cs[i][a] = c;
        }
    }

    vector <int> val (n + 1);
    for (int i = n - m + 1; i <= n; i ++) {
        cin >> val[i];
    }

    const int INF = 1e15;
    vector <vector <int> > dp (n + 1, vector <int> (m + 1, -INF));
    
    vector <int> sz (n + 1);

    auto dfs = [&] (auto self, int u) -> void {
        if (u > n - m) {
            dp[u][1] = val[u];
            dp[u][0] = 0;
            sz[u] = 1;
            return;
        }

        dp[u][0] = 0;

        for (auto v : g[u]) {
            self (self, v);

            for (int i = sz[u]; i >= 0; i --) {
                for (int j = sz[v]; j >= 1; j --) {
                    dp[u][i + j] = max (dp[u][i + j], dp[u][i] - cs[u][v] + dp[v][j]);
                }
            }

            sz[u] += sz[v];
        }
    };

    dfs (dfs, 1);

    // for (int i = 1; i <= n; i ++) {
    //     cerr << "i : " << sz[i] << '\n';
    // }

    int mx = 0;
    for (int i = 0; i <= sz[1]; i ++) {
        // cerr << "i : " << dp[1][i] << '\n';
        if (dp[1][i] >= 0) {
            mx = i; 
        }
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}