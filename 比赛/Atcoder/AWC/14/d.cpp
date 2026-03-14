
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

struct Edge
{
    int to, w;
};

void ovo(){   
    int n, m, t;
    cin >> n >> m >> t;

    vector <vector<Edge>> g (n + 1);
    int u, v, w;
    for (int i = 0; i < m; i ++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    int INF = 1e18;
    auto dijkstra = [&] (int scr) -> vector<int> {
        
        vector <int> dist (n + 1, INF);
        using P = pair <int, int>;
        priority_queue <P, vector <P>, greater<P>> pq;

        dist[scr] = 0;
        pq.push({0, scr});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;
            for (auto &e : g[u]) {
                int v = e.to, nd = d + e.w;
                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }
        return dist;
    };

    vector <int> dist = dijkstra(1);

    if (dist[t] == INF) {
        cout << -1 << '\n';
    } else {
        cout << 2 * dist[t] << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}