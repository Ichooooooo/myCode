
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
        ranges :: iota(fa, 0LL);
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
    int n, m, p;
    cin >> n >> m >> p;

    DSU dsu(n);
    int i, j;
    while (m --) {
        cin >> i >> j;
        dsu.merge(i, j);
    } 
    while (p --) {
        cin >> i >> j;
        int x = dsu.find(i), y = dsu.find(j);
        if (x == y) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}