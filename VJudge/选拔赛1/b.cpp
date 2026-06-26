// 1. 不要看错题目, 路径上的边权最大值 && 路径上的边权和
// 2. 离线处理合并

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr3 = array <int, 3>;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct DSU {
    int n;
    vector <int> fa, rk, sz;

    DSU (int n) : n (n) {
        fa.assign(n + 1, 0);
        iota(fa.begin(), fa.end(), 0LL);
        rk.assign(n + 1, 1);
        sz.assign(n + 1, 1);
    }

    int find (int x) {
        return (x == fa[x]) ? x : fa[x] = find(fa[x]); 
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
    int n, m, q;
    cin >> n >> m >> q;

    vector <arr3> a (m);
    for (int i = 0; i < m; i ++) {
        cin >> a[i][1] >> a[i][2] >> a[i][0];
    }

    sort (a.begin(), a.end());
    DSU dsu (n);

    vector <arr2> qq (q);
    vector <int> ans (q);
    for (int i = 0; i < q; i ++) {
        cin >> qq[i][0];
        qq[i][1] = i;
    }
    sort (qq.begin(), qq.end());

    int now = 0, an = 0;
    
    auto cal = [&] (int x) -> int {
        return x * (x - 1) / 2;
    };

    for (int i = 0; i < q; i ++) {
        auto [cn, ps] = qq[i];
        while (now < m && a[now][0] <= cn) {
            auto [w, u, v] = a[now];
            int s1 = dsu.size(u), s2 = dsu.size(v);

            if (dsu.merge(u, v)) {
                an = an - cal(s1) - cal(s2) + cal(s1 + s2);
            }

            now++;
        }

        ans[ps] = an;
    }

    for (int i = 0; i < q; i ++) {
        cout << ans[i] << " \nn"[i == q - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}