#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m, l, s, t;
    cin >> n >> m >> l >> s >> t;
    //记忆+DFS
    vector<vector<PII>> g(n + 1);
    int a, b, c;
    while (m --) {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
    }

    vector<int> pt;
    auto dfs = [&] (int dep, int u, int p, auto self) -> void  {
        if (dep > l) {
            if (p >= s && p <= t) {
                pt.push_back(u);
            } 
            return;
        }
        for (auto & [x, y] : g[u]) {
            self (dep + 1, x, p + y, self);
        }
    };

    dfs(1, 1, 0, dfs);
    if (pt.empty()) {
        cout << endl;
        return;
    }
    ranges :: sort(pt);
    pt.erase(unique(pt.begin(), pt.end()), pt.end());
    for (int & i : pt) cout << i << ' ';
    cout << endl;
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