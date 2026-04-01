
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
    int n, m, k;
    cin >> n >> m >> k;

    vector <array <int, 3>> a (m);
    for (auto & [x, u, v] : a) {
        cin >> u >> v >> x;
    }

    sort (a.begin(), a.end());

    DSU dsu (n);

    int ans = 0, ok = 0, cnt = n;
    for (int i = 0; i < m; i++) {
        auto [x, u, v] = a[i];

        if (cnt == k) {
            ok = 1;
            break;
        }

        if (dsu.merge (u, v)) {
            cnt--;
            ans += x;
        }


    }

    if (cnt == k) {
        ok = 1;
    }

    if (ok) {
        cout << ans << '\n';
    } else {
        cout << "No Answer" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}