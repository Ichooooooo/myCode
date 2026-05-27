
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
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


struct Node {
    int x; 
    int i, j;
};

void ovo() {
    int n, k;
    cin >> n >> k;
    
    vector <Node> a (k);
    for (int i = 0; i < k; i ++) {
        cin >> a[i].i >> a[i].j >> a[i].x;
    }

    sort (a.begin(), a.end(), [](Node a, Node b){
        return a.x < b.x;
    });

    DSU dsu (n);
    vector <int> vis (k, 0);

    for (int i = 0; i < k; i ++) {
        auto [x, y, z] = a[i];

        if (dsu.merge(y, z)) {
            vis[i] = 1;
        } 
    }

    int ans = 0;
    for (int i = 0; i < k; i ++) {
        auto [x, y, z] = a[i];

        if (!vis[i]) {
            ans += x;
        }
    }

    cout << ans << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}