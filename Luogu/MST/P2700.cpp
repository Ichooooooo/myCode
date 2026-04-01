
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

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
            ranges::iota(fa, 0LL);
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
    int n, k;
    cin >> n >> k;
    
    vector <int> enm (k), vis (n);
    for (int i = 0; i < k; i++) {
        cin >> enm[i];
        vis[enm[i]] = 1;
    }

    vector <array <int, 3>> a (n - 1);

    int tot = 0;
    for (auto & [x, u, v] : a) {
        cin >> u >> v >> x;
        tot += x;
    }

    sort (a.rbegin(), a.rend());

    DSU dsu (n - 1);

    int ans = 0;
    for (int i = 0; i < n - 1; i ++) {
        auto [x, u, v] = a[i];
        
        int r1 = dsu.find(u);
        int r2 = dsu.find(v);

        if (vis[r1] && vis[r2]) continue;

        ans += x;
        if (dsu.merge(u, v)) {
            vis[dsu.find(u)] = (vis[r1] | vis[r2]);
        }
    }

    cout << tot - ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}