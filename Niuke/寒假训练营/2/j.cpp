#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n, m;  cin >> n >> m;

    vector <vector <int>> g (n + 5);
    vector <int> deg (n + 1);

    int u, v;
    for (int i = 0; i < m; i ++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u] ++;  deg[v] ++;
    }

    set <int, greater <int>> st;
    unordered_map <int, vector <int>> mp;
    for (int i = 1; i <= n; i ++) {
        st.insert(deg[i]);
        mp[deg[i]].push_back(i);
    }

    vector <int> ans (n + 1, -1), dist(n + 1, LLONG_MAX);
    queue <int> qu;
    for (auto k : st) {

        for (auto u : mp[k]) {
            ans[u] = (dist[u] == LLONG_MAX ? -1 : dist[u]);
            dist[u] = 0;
            qu.push(u);
        }

        while (!qu.empty()) {
            int u = qu.front();  qu.pop();
            
            for (auto v : g[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    qu.push(v);
                }
            }
        }
    }

    for (int i = 1; i <= n; i ++) cout << ans[i] << " \n"[i == n];

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}