
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m; cin >> n >> m;
    vector <int> deg(n + 1);
     
    vector <vector <int>> rea(n + 1);
    for (int i = 0; i < m; i ++) {
        int u, v; cin >> u >> v;
        deg[v]++;
        rea[u].push_back(v);
    }

    set <int> st;
    for (int i = 1; i <= n; i ++) {
        if (deg[i] == 0) st.insert(i);
    }

    while (!st.empty()) {
        auto po = st.begin();
        for (auto u : rea[*po]) {
            deg[u] --;
            if (deg[u] == 0) st.insert(u);
        }
        cout << *po << ' ';
        st.erase(po);
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}