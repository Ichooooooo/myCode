
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m; cin >> n >> m;
    
    vector <vector <int>> g (n + 1);
    for (int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    for (int i = 1; i <= n; i ++) {
        g[i].push_back (i);
    }

    int w; cin >> w;
    vector <string> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <int> deg (n * w + 1);
    vector <vector <int> > edge (n * w + 1);

    int tot = 0;
    for (int day = 0; day < w; day ++) {
        for (int i = 1; i <= n; i ++) {
            if (a[i][day] == 'o') {
                int id = day * n + i;
                int nd = (day + 1) % w;
                tot++;

                for (auto v : g[i]) {
                    if (a[v][nd] == 'o') {
                        int vid = nd * n + v;
                        edge[id].push_back (vid);
                        deg[vid]++;
                    }
                }
            }
        }
    }

    queue <int> qu;
    int cnt = 0;
    for (int i = 0; i < w; i ++) {
        for (int j = 1; j <= n; j ++) {
            int id = i * n + j;
            if (a[j][i] == 'o' && deg[id] == 0) {
                qu.push(id);
            }
        }
    }

    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        cnt++;

        for (auto v : edge[u]) {
            if (--deg[v] == 0) {
                qu.push(v);
            }
        }
    }

    if (cnt < tot) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}