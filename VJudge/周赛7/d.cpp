
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, k;
    cin >> n >> k;

    vector <vector <int> > g (n + 1);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int mx = 1;

    auto dfs = [&] (auto self, int u, int fa, int dep) -> void {
        
        for (auto v : g[u]) {
            if (v == fa) continue;

            self (self, v, u, dep + 1);
        }

        mx = max (mx, dep);
    };

    for (auto v : g[k]) {
        dfs (dfs, v, k, 1);    
    }

    cout << mx + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}