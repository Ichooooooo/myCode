
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
    int n, m, x, d;
    cin >> n >> m >> x >> d;
    vector <array <int, 2>> hgt(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> hgt[i][0];
        hgt[i][1] = i;
    }

    sort (hgt.begin() + 1, hgt.end());

    vector <vector <int>> a (n + 1);
    
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    // 每天的水
    vector <int> vis (n + 1, false), riv (x + 1);
    for (int i = 1; i <= x; i ++) cin >> riv[i];

    DSU dsu(n);
    vector <int> ans;
    ans.reserve(x + 1);

    int cnt = 0;

    for (int i = x; i >= 1; i --) {
        int p = upper_bound(hgt.begin() + 1, hgt.end(), array<int, 2>{riv[i], n + 1}) - hgt.begin();

        for (int j = p; j <= n; j ++) {
            int u = hgt[j][1];
            if (vis[u]) {
                break;
            }
            vis[u] = true;
            if (d == 1) cnt ++;
            for (auto v : a[u]) {
                if (!vis[v]) continue;
                int f1 = dsu.find(u);
                int f2 = dsu.find(v); 
                int s1 = dsu.size(f1);
                int s2 = dsu.size(f2);
                if (dsu.merge(u, v)) {
                    if (s1 + s2 >= d) {
                        cnt -= (s1 >= d);
                        cnt -= (s2 >= d);
                        cnt += 1;
                    }
                    
                }
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