
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct DSU {
    int n;
    vector <int> fa, rk, sz;

    DSU (int n) : n (n) {
        fa.assign (n + 1, 0);
        iota(fa.begin(), fa.end(), 0LL);
        rk.assign (n + 1, 1);
        sz.assign (n + 1, 1);
    }

    int find (int i) {
        return (i == fa[i] ? i : fa[i] = find(fa[i]));
    }

    bool merge (int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;

        if (rk[x] < rk[y]) swap (x, y);
        fa[y] = x;
        if (rk[x] == rk[y]) rk[x]++;
        sz[x] += sz[y];

        return true;
    }

    int size (int x) {
        return sz[find(x)];
    }
};

void ovo() {
    int n;
    cin >> n;

    vector <vector <int> > g (n + 1);
    vector <int> cnt (n + 1);

    DSU dsu (n);
    int ok1 = 0;
    for (int i = 1; i <= n; i ++) {
        int u, v;
        cin >> u >> v;
        if (u == v) ok1 = 1; 
        g[u].push_back(v); 
        g[v].push_back(u);

        dsu.merge(u, v);
        cnt[u]++;
        cnt[v]++;
    }

    if (ok1) {
        cout << "NO" << '\n';
        return;
    }
    
    vector <int> tmp; tmp.reserve(n);
    int ok = 0;
    for (int i = 1; i <= n; i ++) {
        if (cnt[i] > 2) {
            ok = 1;
            break;
        }
        int sz = dsu.size(i);
        if (i == dsu.find(i) && (sz) != 1) {
            // cerr << "fa : " << i << '\n';
            tmp.push_back(i);
        }
    }

    if (ok) {
        cout << "NO" << '\n';
        return;
    }

    vector <int> vis (n + 1, -1);
    
    for (int i = 0; i < tmp.size(); i ++) {
        int x = tmp[i];
        vis[x] = 1;
        queue<arr2> qu;
        qu.push({x, 1});

        while (qu.size()) {
            auto [u, op] = qu.front(); qu.pop();
            for (auto v : g[u]) {
                if (vis[v] != -1) {
                    if (vis[v] != (1LL ^ op)) {
                        ok = 1;
                        break;
                    } else {
                        continue;
                    }
                }

                qu.push({v, (1LL ^ op)});
                vis[v] = (1LL ^ op);
                // cerr << "v : " << v << ' ' << vis[v] << '\n'; 
            }
        }

        if (ok) break;
    }

    if (ok) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}