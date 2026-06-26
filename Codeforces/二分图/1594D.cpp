
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <vector <arr2> > g (n + 1);
    
    for (int k = 1; k <= m; k ++) {
        int i, j; string c;
        cin >> i >> j >> c;
        if (c == "imposter") {
            g[i].push_back({j, 1});
            g[j].push_back({i, 1});
        } else {
            g[i].push_back({j, 0});
            g[j].push_back({i, 0});
        }
    }

    vector <int> vis (n + 1, -1);

    int ans = 0, ok = 1;
    for (int i = 1; i <= n; i ++) {
        if (vis[i] != -1) continue;

        int cnt = 0, cn = 0;
        queue <int> qu;
        qu.push(i);
        vis[i] = 1;
        
        while (qu.size()) {
            auto x = qu.front(); qu.pop();
            if (vis[x] == 1) cn++;
            cnt++;

            for (auto [v, op] : g[x]) {
                if (vis[v] == -1) {
                    vis[v] = (op ^ vis[x]);
                    qu.push(v);
                } else {
                    if (vis[v] != (op ^ vis[x])) {
                        cout << -1 << '\n';
                        return;
                    }
                }
            }
        }

        // cerr << "i : " << i << ' ' << cnt << ' ' << cn << '\n'; 
        ans += max (cnt - cn, cn);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}