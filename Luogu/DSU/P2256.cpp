
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
    int n, m, k;
    cin >> n >> m;

    unordered_map <string, int> mp;
    mp.reserve(n);
    string s;
    for (int i = 1; i <= n; i ++) {
        cin >> s;
        mp[s] = i;
    }

    DSU dsu(n);
    string x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        dsu.merge(mp[x], mp[y]);
    }

    cin >> k;
    while (k --) {
        cin >> x >> y;
        // cout << "uuuuuu";
        if (dsu.find(mp[x]) == dsu.find(mp[y])) {
            cout << "Yes." << '\n';
        } else {
            cout << "No." << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}