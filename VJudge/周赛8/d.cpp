
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
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
    int n; cin >> n;

    vector <arr2> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    const int INF = 1e17;

    vector <arr3> edge;
    edge.reserve (n * n + 10);
    for (int i = 1; i <= n; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            auto [x1, y1] = a[i];
            auto [x2, y2] = a[j];

            int tmn = min (abs (x1 - x2), abs (y1 - y2));
            int tmx = max (abs (x1 - x2), abs (y1 - y2));
            int dis = (tmn + tmx + 1) / 2;
            edge.push_back ({dis, i, j});
        }
    }

    sort (edge.begin(), edge.end());

    DSU dsu (n);

    int mx = 0;
    for (int i = 0; i < (int)edge.size(); i ++) {
        auto [dis, x, y] = edge[i];

        if (dsu.merge (x, y)) {
            mx = max (mx, dis);
        }
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}