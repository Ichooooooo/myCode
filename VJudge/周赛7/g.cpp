
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 32;

void ovo() {
    int n; cin >> n;
    
    vector <vector <arr2> > g (N + n + 5);
     
    for (int i = N; i <= N + n - 1; i ++) {
        int x; cin >> x;
        
        for (int bit = 0; bit < N; bit++) {
            if ((x >> bit) & 1) {
                g[i].push_back({bit, x});
                g[bit].push_back({i, x});
            }
        }
    }

    const int INF = 1e15;
    vector <int> dist (N + n + 5, INF);
    dist[N] = 0;
    priority_queue <pair <int, int> , vector <pair <int, int> >, greater <pair <int, int> > > pq;
    pq.push({0, N});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();

        // cerr << "pq : " << u << ' ' << d << '\n';

        if (d != dist[u]) continue;

        for (auto [v, dd] : g[u]) {
            // cerr << "v : " << v << ' ' << dd << '\n';

            int td = dd + d;
            
            if (td < dist[v]) {
                dist[v] = td;
                pq.push({td, v});
            }
        }
    }

    for (int i = N; i <= N + n - 1; i ++) {
        if (dist[i] >= INF) {
            cout << -1 << ' ';
        } else {
            cout << dist[i] << ' ';
        }
    }  

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}