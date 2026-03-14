#include<bits/stdc++.h>
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

void ovo(){   
    int n; cin >> n;
    vector <int> a (n + 1);
    DSU dsu (n);
    
    for (int i = 1; i <= n; i ++) cin >> a[i];

    for (int i = 1; i <= n; i ++) {
        dsu.merge (i, a[i]);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (dsu.find(i) == i) cnt ++;
    }

    int ans = n - cnt, ok = 0;
    for (int i = 1; i < n; i ++) {
        if (dsu.find(i) == dsu.find(i + 1)) {
            ok = 1; break;
        }
    }

    cout << (ok ? (ans - 1) : (ans + 1)) << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}