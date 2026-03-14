
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
    vector <vector <int>> a (n);
    int u, v;
    for (int i = 0; i < m; i ++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    DSU dsu(n - 1);
    int k;
    cin >> k;

    vector <int> vis (n, true), kill (k);

    for (int & i : kill) {
        cin >> i;
        vis[i] = false;
    }

    int cnt = n - k;
    vector <int> ans;
    for (int u = 0; u < n; u ++) {
        if (!vis[u]) continue;
        for (auto v : a[u]) {
            if (!vis[v]) continue;
            if (dsu.merge(v, u)) {
                cnt --;
            }
        }
    }
    ans.push_back(cnt);
    
    for (int i = kill.size() - 1; i >= 0; i --) {
        int u = kill[i];
        vis[u] = true;
        cnt ++;
        for (auto v : a[u]) {
            if (!vis[v]) continue;
            if (dsu.merge(u, v)) {
                cnt --;
            }
        }
        ans.push_back(cnt);
    }

    for (int i = ans.size() - 1; i >= 0; i --) {
        cout << ans[i] << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}