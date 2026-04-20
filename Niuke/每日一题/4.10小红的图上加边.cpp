#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

class DSU {
public:
    vector <int> fa, rk, sz;

    DSU (int n) {
        init (n);
    }

    void init (int n) {
        fa.resize (n + 1);
        iota(fa.begin(), fa.end(), 0LL);
        rk.assign (n + 1, 1);
        sz.assign (n + 1, 1);
    }

    int find (int x) {
        return (fa[x] == x ? x : (fa[x] = find (fa[x]))); 
    }

    bool merge (int i, int j) {
        int x = find (i);
        int y = find (j);

        if (x == y) return false;
        
        if (rk[x] < rk[y]) swap (x, y);
        fa[y] = x;
        sz[x] += sz[y];
        if (rk[x] == rk[y] ) rk[x] ++;
        return true;
    }

    int size (int x) {
        return sz[x];
    }

};

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    const int INF = 1e15;
    vector <int> fa (n + 1, -1);

    DSU dsu(n);
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        
        dsu.merge (u, v);
    }

    for (int i = 1; i <= n; i ++) {
        int x = dsu.find(i);
        fa[x] = max (fa[x], a[i]);
    }

    int sum = 0, mn = INF;
    for (int i = 1; i <= n; i ++) {
        if (fa[i] == -1) continue;
        sum += fa[i];
        mn = min (mn, fa[i]);
    }

    cout << sum - mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}