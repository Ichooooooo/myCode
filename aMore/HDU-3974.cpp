#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct SegTree {
    struct node {
        int l, r;
        i64 x, lz;
    };

    int n;
    vector <i64> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, -1);
        tr.assign(4 * n + 10, {});
    }

    void push_down (int p) {
        if (tr[p].lz != -1) {
            tr[p << 1].x = tr[p << 1 | 1].x = tr[p].x;
            tr[p << 1].lz = tr[p << 1 | 1].lz = tr[p].lz;
            tr[p].lz = -1;
        }
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, -1, -1};
        if (l == r) {
            tr[p].x = -1;
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
    }

    void modify (int p, int l, int r, int t) {
        if (l <= tr[p].l && tr[p].r <= r) {
            tr[p].x = tr[p].lz = t;
            return;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (l <= mid) modify(p << 1, l, r, t);
        if (mid < r) modify(p << 1 | 1, l, r, t);
    }

    int query (int p, int x) {
        if (tr[p].l == tr[p].r) {
            return tr[p].x;
        }
        push_down(p);
        int mid = (tr[p].l + tr[p].r) >> 1;
        if (x <= mid) return query(p << 1, x);
        else return query(p << 1 | 1, x);
    }
};

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > e(n + 1);
    vector <int> ind(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
        ind[u]++;
    }

    int r;
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            r = i;
            break;
        }
    }

    vector <int> sz(n + 1);
    vector <int> dfn(n + 1);
    int c = 1;
    
    auto dfs = [&] (auto self, int fa, int u) -> void {
        int cur = 1;
        dfn[u] = c++;
        for (auto v : e[u]) {
            if (v == fa) continue;
            self(self, u, v);
            cur += sz[v];
        }
        sz[u] = cur;
    };
    dfs(dfs, -1, r);

    SegTree seg(n);
    seg.build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        char op;
        cin >> op;
        if (op == 'C') {
            int x;
            cin >> x;
            cout << seg.query(1, dfn[x]) << '\n';
        }else {
            int x, y;
            cin >> x >> y;
            int l = dfn[x];
            int r = dfn[x] + sz[x] - 1;
            seg.modify(1, l, r, y);
        }
    }
}

int main ()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    int __ = 1;
    cin >> _;
    while (_--) {
        cout << "Case #" << __ << ":\n";
        __++;
        solve();
    }
    return 0;
}