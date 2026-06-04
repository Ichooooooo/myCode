// trick : 子树之间在没处理的时候就有了cnt, 这时候可以提前减掉

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct BIT  {
    int n; 
    vector <int> bit;

    BIT (int x) : n (x) {
        bit.assign (n + 5, 0);
    } 

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x ;i >= 1; i -= lowbit (i)) {
            ans += bit[i];
        }
        return ans;
    }
};


void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1), b (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    }

    vector <int> fa (n + 1);
    vector <vector <int> > g (n + 1);
    for (int i = 2; i <= n; i ++) {
        cin >> fa[i];
        g[fa[i]].push_back (i);
    }
  
    sort (b.begin() + 1, b.end());
    b.erase (unique (b.begin() + 1, b.end()));

    int m = b.size();
    for (int i = 1; i <= n; i ++) {
        a[i] = lower_bound (b.begin() + 1, b.end(), a[i]) - b.begin();
    }

    BIT bit (m);
    vector <int> ans (n + 1);
    auto dfs = [&] (auto self, int u) -> void {
        ans[u] -= (bit.sum (m) - bit.sum(a[u]));

        // cerr << "u : " << u << ' ' << ans[u] << '\n';
        
        for (auto v : g[u]) {
            self (self, v);
        }
        
        ans[u] += (bit.sum (m) - bit.sum(a[u]));
        bit.point_add (a[u], 1);
        // cerr << "u : " << u << ' ' << ans[u] << '\n';            
    };

    dfs (dfs, 1);
    for (int i = 1; i <= n; i ++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}