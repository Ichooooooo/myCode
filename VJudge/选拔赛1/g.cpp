// dij和状压写法分别都有一些问题

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;
    
    vector <vector <arr2> > g (n + 1);
    for (int i = 0; i < m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    int sz; cin >> sz;
    unordered_map <int, int> mp;
    mp[0] = 0;
    for (int i = 1; i <= sz; i ++) {
        int x; cin >> x;
        mp[x] = i;
    }

    const int INF = 1e15;
    vector <vector <int>> dis (sz + 1, vector <int> (sz + 1, INF));

    auto dij = [&] (int src) -> void {
        int ps = mp[src];
        priority_queue <arr2, vector <arr2>, greater <arr2> > pq;

        // 1. 初始化dist为INF
        vector <int> dist (n + 1, INF);
        // 2. pq距离放在前面
        pq.push({0, src});
        dist[src] = 0;

        while (pq.size()) {
            auto [to, u] = pq.top(); pq.pop();

            // 3. 过期状态去掉
            if (to != dist[u]) continue;

            if (mp.find(u) != mp.end()) {
                dis[mp[u]][ps] = dist[u];
                dis[ps][mp[u]] = dist[u];
            }

            for (auto [v, w] : g[u]) {
                if (to + w >= dist[v]) continue;

                dist[v] = to + w;
                pq.push({dist[v], v});
            }
        }
    };

    for (int i = 0; i <= sz; i ++) {
        dis[i][i] = 0;
    }

    for (auto [x, y] : mp) {
        dij(x);
        // cerr << "i : " << x << ' ' << dis[0][x] << '\n'; 
    }

    int len = 1LL << sz;
    // 1. 初始化dp
    vector <vector <int> > dp (len, vector <int> (sz + 1, INF));
    dp[0][0] = 0;

    // 因为从前往后转移, 所以从mask从0开始
    for (int i = 0; i < len; i ++) {
        for (int j = 0; j <= sz; j ++) {
            // 2. 不合法的状态为INF, 所以跳过
            if (dp[i][j] == INF) continue;

            for (int k = 1; k <= sz; k ++) {
                int bit = (1LL << (k - 1));
                if (i & bit) continue;
                
                dp[i | bit][k] = min (dp[i | bit][k], dp[i][j] + dis[j][k]);
            }
        }
    }

    int mn = INF;
    for (int i = 0; i <= sz; i++) {
        mn = min(mn, dp[len - 1][i] + dis[i][0]);
    }

    cout << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}