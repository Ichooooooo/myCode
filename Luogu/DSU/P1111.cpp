
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
    int n, m;
    cin >> n >> m;

    DSU dsu (n + 1);
    map <int, vector<array<int, 2>>> mp;

    int x, y, t;
    for (int i = 0; i < m; i ++) {
        cin >> x >> y >> t;
        mp[t].push_back({x, y});
    }

    int time = -1;
    for (auto [t, a] : mp) {
        for (auto [x, y] : a) {
            dsu.merge(x, y);
        }

        if (dsu.size(1) == n) {
            time = t;
            break;
        }
    }

    cout << time << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}