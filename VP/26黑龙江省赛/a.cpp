#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr4 = array <int, 4>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;
    
    vector <vector <int> > g (n + 1);
    for (int i = 1; i <= n -1 ; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    vector <int> op (m + 1), tim (m + 1), s (m + 1), t (m + 1);
    for (int i = 1; i <= m; i ++) {
        cin >> op[i] >> tim[i] >> s[i] >> t[i];
    }

    vector <vector <int> > path (m + 1);
    vector <int> sz (m + 1);
    auto dfs = [&] (auto self, int p, int u, int fa, int ed) -> bool {
        if (u == ed) {
            path[p].push_back (ed);
            return true;
        }

        int ok = 0;
        for (auto v : g[u]) {
            if (v == fa) continue;
            ok = 1;
            if (self (self, p, v, u, ed)) {
                path[p].push_back (u);
                return true;
            }
        }

        return false;
    };

    for (int i = 1; i <= m; i ++) {
        if (s[i] == t[i]) {
            path[i].push_back (s[i]);
            sz[i] = (int)path[i].size();
        } else {
            dfs (dfs, i, s[i], 0, t[i]);
            sz[i] = (int)path[i].size();
        }
    }

    int time = 0;
    vector <int> win; win.reserve (m + 5);
    vector <int> tag (m + 1);
    int loss = 0;

    while ((int)(win.size() )+ loss < m) {
        time++;

        for (int i = 1; i <= m; i ++) {
            if (!tag[i] && sz[i] <= time + 1) {
                win.push_back (i);
                tag[i] = 1;
            }
        }

        vector <vector <int> > dist (n + 1);
        for (int i = 1; i <= m; i ++) {
            if (!tag[i]) {
                int pos = sz[i] - 1 - time;
                dist[path[i][pos]].push_back (i);
            }
        }

        // for (int i = 1; i <= n; i ++) {
        //     cout << "time = " << time << ", dist[" << i << "]:";
        //     for (auto j : dist[i]) cout << ' ' << j;
        //     cout << '\n';
        // }

        vector <arr4> jug (n + 1);
        for (int i = 1; i <= n; i ++) {
            for (auto j : dist[i]) {
                if (op[j] == 1 && time % tim[j] == 0) {
                    jug[i][0] = 1;
                } else if (op[j] == 2 && time % tim[j] == 0) {
                    jug[i][1] = 1;
                } else if (op[j] == 3 && time % tim[j] == 0) {
                    jug[i][2] = 1;
                } else if (op[j] == 4 && time % tim[j] == 0) {
                    jug[i][3] ++;
                }
            }
        }

        vector <int> die (m + 1);
        for (int i = 1; i <= n; i ++) {
            for (auto j : dist[i]) {
                if (jug[i][1] && op[j] == 1) {
                    tag[j] = 1;
                    die[j] = 1;
                    // cout << "loss " << j << '\n';
                }
                if (jug[i][2] && op[j] == 2) {
                    tag[j] = 1;
                    die[j] = 1;
                    // cout << "loss " << j << '\n';
                }
                if (jug[i][3] && (op[j] == 2 || op[j] == 3)) {
                    tag[j] = 1;
                    die[j] = 1;
                    // cout << "loss " << j << '\n';
                }
                int self = (time % tim[j] == 0);
                if ((jug[i][3] - self) && op[j] == 4) {
                    tag[j] = 1;
                    die[j] = 1;
                }

                
                if (jug[i][0] && jug[i][1] == 0 && (op[j] == 2 || op[j] == 3 || op[j] == 4)) {
                    tag[j] = 1;
                    die[j] = 1;
                    // cout << "loss " << j << '\n';
                }
            }
        }

        for (int i = 1; i <= m; i ++) {
            loss += die[i];
        }
    }

    cout << win.size() << '\n';
    sort (win.begin(), win.end());

    for (int i = 0; i < win.size(); i ++) {
        cout << win[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}