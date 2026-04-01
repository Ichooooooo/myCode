
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > a (m, vector <int> (n));
    vector <vector <int> > vis (n + 1, vector <int> (n + 1));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
        }
    }

    // cout << n << ' ' << m << '\n';

    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j ++) {
            int u = a[i][j  - 1], v = a[i][j];

            // cerr << i << ' ' << j << '\n';
            // cerr << u << ' ' << v << '\n';

            vis[u][v] = 1;
            vis[v][u] = 1;
        }
    }    

    int ans = 0;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i == j) continue;
            if (!vis[i][j]) ans++;
        }
    }

    cout << ans / 2 << '\n';
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}