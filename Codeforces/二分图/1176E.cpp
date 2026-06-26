
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > g (n + 1);
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> vis (n + 1, -1);
    queue <int> qu;

    qu.push(1);
    vis[1] = 1;
    int cnt = 0;

    while (qu.size()) {
        int u = qu.front(); qu.pop();

        if (vis[u]) cnt++;
        for (auto v : g[u]) {
            if (vis[v] != -1) continue;
            
            vis[v] = (1LL ^ vis[u]);
            qu.push(v);
        }
    }

    if (n > 2 * cnt) {
        cout << cnt << '\n';
        for (int i = 1; i <= n; i ++) {
            if (vis[i]) cout << i << ' ';
        }
        cout << '\n';
    } else {
        cout << n - cnt << '\n';
        for (int i = 1; i <= n; i ++) {
            if (!vis[i]) cout << i << ' ';
        }
        cout << '\n';        
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}