// 排序顺序 : 询问可以按照边权从小到大, 且之前的不用删除
// 数据结构维护 : DSU维护哪些节点已经连通在一起
// 模型 : 最大边权路径查询 

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

struct DSU {
    int n;
    vector <int> fa, rk, sz;

    DSU (int n) : n (n) {
        fa.assign (n + 5, 0);
        iota (fa.begin(), fa.end(), 0LL);
        rk.assign (n + 5, 1);
        sz.assign (n + 5, 1);
    }

    int find (int x) {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    }

    bool merge (int i, int j) {
        int x = find (i), y = find (j);

        if (x == y) return false;

        if (rk[x] < rk[y]) swap (x, y);
        fa[y] = x;
        if (rk[x] == rk[y]) rk[x]++;
        sz[x] += sz[y];

        return true;
    };

    int size (int x) {
        return sz[find(x)];
    }
};

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <arr3> g (n - 1);
    for (int i = 0; i < n - 1; i ++) {
        cin >> g[i][1] >> g[i][2] >> g[i][0];
    }

    sort (g.begin(), g.end());

    vector <int> ans (m);
    vector <arr2> b (m);
    for (int i = 0; i < m; i ++) {
        cin >> b[i][0];
        b[i][1] = i;
    }

    sort (b.begin(), b.end());

    int now = 0;
    DSU dsu (n);

    auto cal = [&] (int x) -> int {
        return x * (x - 1) / 2;
    };

    int an = 0;
    for (int i = 0; i < m; i ++) {
        cerr << "i : " << i << ' ' << b[i][0] << '\n';

        while (now < n - 1 && g[now][0] <= b[i][0]) {
            int c1 = dsu.size(g[now][1]);
            int c2 = dsu.size(g[now][2]);

            if (dsu.merge (g[now][1], g[now][2])) {
                // cerr << "c : " << c1 << ' ' << c2 << ' ' << dsu.size(g[now][1]) << '\n';
                an = an - cal(c1) - cal(c2) + cal(dsu.size(g[now][1]));
            }

            now ++;
        }

        ans[b[i][1]] = an;
    }

    for (int i = 0; i < m; i ++) {
        cout << ans[i] << " \n"[i == m - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}