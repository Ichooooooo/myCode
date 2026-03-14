#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, w;
};

vector<int> dijkstra(int n, int src, const vector<vector<Edge>>& g, vector<int>& parent) {
    vector<int> dist(n + 1, INF);
    parent.assign(n + 1, -1);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    parent[src] = src;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &e : g[u]) {
            int v = e.to, nd = d + e.w;
            if (nd < dist[v]) {
                dist[v] = nd;
                parent[v] = u;
                pq.push({nd, v});
            }
        }
    }
    return dist;
}

vector<int> get_path(int src, int t, const vector<int>& parent) {
    if (t <= 0 || t >= (int)parent.size() || parent[t] == -1) return {};
    vector<int> path;
    for (int cur = t;; cur = parent[cur]) {
        path.push_back(cur);
        if (cur == src) break;
        if (cur == -1) return {};
    }
    reverse(path.begin(), path.end());
    return path;
}