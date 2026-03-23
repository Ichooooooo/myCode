
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

struct Edge {
    int to;
    int w;
};

vector<int> dijkstra(int n, int src, const vector<vector<Edge>>& g) {
    vector<int> dist(n + 1, LLONG_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d != dist[u]) continue;

        for (auto e : g[u]) {
            int v = e.to;
            int nd = d + e.w;     
            if (nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
            }
        }
    }
    return dist;
}

void ovo(){   
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}