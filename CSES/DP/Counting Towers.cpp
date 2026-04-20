#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
using i128 = __int128;


void ovo() {
    int n;
    cin >> n;
    vector<int> a(n + 5, 0), ans(n + 5, 0);
    vector<vector<int>> e(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    map<int, int> tmp1, tmp0;
    auto dfs =[&] (auto& dfs, int u, int from, int val, map<int, int> tmp) -> void {
        tmp1.clear();
        ans[u] = max(ans[u], gcd(val, a[u])); 
        ans[u] = max(ans[u], val); 
        for (auto [x, y] : tmp) {
            ans[u] = max(ans[u], gcd(a[u], x));
            tmp1[gcd(x, a[u])] = 1;
        }
        tmp = tmp1;
        tmp[val] = 1;
        for (int v : e[u]) {
            if (v == from) continue;
            dfs(dfs, v, u, gcd(val, a[u]), tmp);
        }
    };
    dfs(dfs, 1, 0, 0, tmp0);
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}