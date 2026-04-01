
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

class DSU {
public:
    vector <int> fa, rk, sz;
    DSU (int n) {
        init(n);
    }

    void init (int n) {
        fa.resize(n + 1);
        iota(fa.begin(), fa.end(), 0LL);
        rk.assign(n + 1, 1LL);
        sz.assign(n + 1, 1LL);
    }

    int find (int x) {
        return (x == fa[x] ? x : (fa[x] = find (fa[x])));
    }

    bool merge (int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false;
        
        if (rk[x] < rk[y]) swap (x, y);
        fa[y] = x;
        sz[x] += sz[y];
        if (rk[x] == rk[y]) rk[x]++;
        return true;
    }

    int size (int j) {
        return sz[find(j)];
    }
};

void ovo() {
    int n, m, k;
    cin >> n >> m >> k;

    vector <array <int, 2> > a, b; a.reserve (n), b.reserve (n);

    for (int i = 0; i < m; i ++) {
        int u, v, op;
        cin >> u >> v >> op;
        
        if (op == 1) {
            a.push_back ({u, v});
        } else {
            b.push_back ({u, v});
        }
    }

    DSU dsu1 (n);
    vector <array<int, 3>> ans; ans.reserve(n);
    
    // 判断最少
    int as = a.size(), bs = b.size();
    for (auto [u, v] : a) {
        dsu1.merge(u, v);
    }

    int mn = 0;
    for (auto [u, v] : b) {
        if (dsu1.merge(u, v)) {
            mn++;
            ans.push_back ({u, v, 0});
        }
    }

    if (k < mn) {
        cout << "no solution" << '\n';
        return;
    }

    DSU dsu2 (n);
    int mx = 0;
    
    // 判断最多
    for (auto [u, v] : b) {
        if (dsu2.merge(u, v)) {
            mx++;
        }
    }

    if (k > mx) {
        cout << "no solution" << '\n';
        return;
    }

    DSU dsu (n);
    int nm = 0, lt = n;
    for (auto [u, v, op] : ans) {
        dsu.merge (u, v);
        nm++;
        lt--;
    }

    for (auto [u, v] : b) {
        if (nm == k) break;

        if (dsu.merge(u, v)) {
            nm++;
            lt--;
            ans.push_back({u, v, 0});
        }
    }

    for (auto [u, v] : a) {
        if (dsu.merge(u, v)) {
            ans.push_back ({u, v, 1});
            lt--;
        }
    }

    if (lt != 1) {
        cout << "no solution" << '\n';
        return;
    }

    for (auto [u, v, op] : ans) {
        cout << u << ' ' << v << ' ' << op << '\n';
    }
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}