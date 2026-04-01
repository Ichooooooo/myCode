
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <vector <int>> g (n + 1);
    vector <int> deg (n + 1);
    for (int i = 0; i < n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        deg[u]++; deg[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int ok = 0;
    auto dfs = [&] (int u, int fa, auto self) -> bool {

        int cnt = 0;
        for (auto v : g[u]) {
            if (v == fa) continue;
            cnt += self(v, u, self);
        }

        if (deg[u] == 1) return 1;
        
        return (cnt >= 2);
    };

    int ans = 0;
    for (auto str : g[1]) {
        ans += dfs (str, 1, dfs);
    }


    if (ans) {
        cout << "red" << '\n';
    } else {
        cout << "purple" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}