
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
    
    void init(int n) {
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

        if (rk[x] < rk[y]) swap (x, y);
        fa[y] = x;
        if (rk[x] == rk[y]) rk[x] ++;
        sz[x] += sz[y];

        return true;
    } 

    int size (int i) {
        int x = find(i);
        return sz[x];
    }
};

void ovo(){   
    int n, m; cin >> n >> m;

    DSU dsu (2 * n);
    char opt; int x, y;

    auto opp = [&](int x) -> int {
        if (x <= n) return x + n;
        else return x - n;
    };

    for (int i = 0; i < m; i++) {
        cin >> opt >> x >> y;
        if (opt == 'F') {
            dsu.merge(x, y);
            // dsu.merge(opp(x), opp(y));  
        } else {
            dsu.merge(x, opp(y));
            dsu.merge(y, opp(x));
        }
    }
    
    vector <int> root; 
    root.reserve(n);

    for (int i = 1; i <= n; i ++) {
        int x = dsu.find(i);
        root.push_back(x);
    }

    ranges :: sort (root);
    root.erase(unique(root.begin(), root.end()), root.end()); 

    cout << root.size() << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}