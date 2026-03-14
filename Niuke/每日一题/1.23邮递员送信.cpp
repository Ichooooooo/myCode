#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

struct Edge 
{
    int to;
    int w;
};


void solve(){   
    int n, m;
    cin >> n >> m;
    
    vector <vector<Edge>> g (n + 1), rg (n + 1);
    int u, v, w;
    for (int i = 0; i < m; i ++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        rg[v].push_back({u, w});
    }

    auto Dijkstra = [&] (vector <vector<Edge>> & g, int scr) -> vector <int> {
        vector <int> dist (n + 1, LLONG_MAX);
        priority_queue <PII, vector<PII>, greater<PII>> pq;
        dist[scr] = 0;
        pq.push({0, scr});

        while (! pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;

            for (auto x : g[u]) {
                int v = x.to;
                int dis = d + x.w;
                if (dis < dist[v]) {
                    dist[v] = dis;
                    pq.push({dis, v});
                }
            }
        }
        
        return dist;
    };

    vector <int> ag = Dijkstra (g, 1);
    vector <int> arg = Dijkstra (rg, 1);

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = ans + ag[i] + arg[i];
    }

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}