
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
    int n, m;
    cin >> n >> m;
    vector <array <int, 3>> a (m);
    for (int i = 0; i < m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        a[i] = {w, u, v};
    }

    sort (a.begin(), a.end());
    DSU dsu(n);

    int ans = 0;
    for (int i = 0; i < m; i ++) {
        auto [w, u, v] = a[i];
        if (dsu.merge(u, v)) {
            ans += w;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (dsu.find(i) == i) cnt++;
    }

    if (cnt == 1) {
        cout << ans << '\n';
    } else {
        cout << "orz" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}