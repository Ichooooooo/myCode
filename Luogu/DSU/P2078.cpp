
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
            iota(fa.begin(), fa.end(), 0);
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
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    vector <int> a (n + m + 2);
    int x, y;

    DSU dsu(n + m + 2);

    dsu.merge(-1 + m + 1, 1 + m + 1);
    while (p --) {
        cin >> x >> y;
        dsu.merge(x + m + 1, y + m + 1);
    }

    while (q --) {
        cin >> x >> y;
        dsu.merge(x + m + 1, y + m + 1);
    }
    
    int fa = dsu.find(1 + m + 1);
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n + m + 1; i ++) {
        int x = dsu.find(i);
        if (x == fa) {
            if (i >= 1 && i <= -1 + m + 1) c1++;
            else if (i > -1 + m + 1) c2 ++; 
        } 
    }

    cout << min (c1, c2) << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}