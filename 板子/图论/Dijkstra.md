```cpp
const int INF = (int)4e18;

struct Dij {
    int n;
    vector<vector<pair<int, int>>> e;
    vector<int> dis;
    vector<bool> vis;

    Dij(int n) {
        this->n = n;
        e.resize(n + 2);
        dis.assign(n + 2, INF);
        vis.assign(n + 2, false);
        for (int i = 1; i <= n; i++) e[i].clear();
    }

    void di(int s) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        dis[s] = 0;
        q.push(pair<int, int>{0, s});

        while (!q.empty()) {
            auto it = q.top();
            q.pop();
            int u = it.second;
            if (vis[u]) continue;
            vis[u] = true;

            for (auto [v, w] : e[u]) {
                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    q.push(pair<int, int>{dis[v], v});
                }
            }
        }
    }
};
