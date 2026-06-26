
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

class DSU {
    public: 
        vector <int> fa, rk, sz;
        DSU (int n = 0) {
            init(n); 
        }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            sz.assign(n + 1, 1);
            iota(fa.begin(), fa.end(), 0LL);
        }

        int find (int x) {
            return x == fa[x] ? x : (fa[x] = find(fa[x]));
        }

        bool merge (int i, int j) {
            int x = find(i), y = find(j);
            if (x == y) return false;
            if (rk[x] < rk[y]) swap(x, y);
            fa[y] = x;
            sz[x] += sz[y]; 
            if (rk[x] == rk[y]) rk[x]++;
            return true;
        }

        int size (int x) {
            return sz[find(x)];
        }
};

void ovo() {
    int n, m;
    cin >> n >> m;

    DSU dsu (n + 1);
    vector <vector <int> > g (n + 1);

    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);

        dsu.merge(u, v);
    }

    vector <int> tmp; tmp.reserve(n);
    for (int i = 1; i <= n; i ++) {
        if (i == dsu.find(i)) {
            tmp.push_back(i);
        }
    }

   
    int ans = 0;
    vector <int> vis (n + 1, -1);

    for (int i = 0; i < tmp.size(); i ++) {
        int cnt = 1, cn = 1, ok = 0;
        queue <arr2> qu;
        qu.push({tmp[i], 1});
        vis[tmp[i]] = 1;

        while (qu.size()) {
            auto [x, op] = qu.front(); qu.pop();

            for (auto y : g[x]) {
                if (vis[y] != -1) {
                    if (vis[y] != (1LL ^ (op))) {
                        ok = 1;
                        break;
                    } else {
                        continue;
                    }
                }

                qu.push({y, (1LL ^ op)});
                vis[y] = (1LL ^ op);
                if ((1LL ^ op) == 1) cn++;
                cnt++;
            }

            if (ok == 1) {
                break;
            }
        }

        if (ok == 1) continue;
        ans += max (cn, cnt - cn);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}