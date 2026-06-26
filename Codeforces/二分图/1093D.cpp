
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;

int qpow (int x, int y) {
    int res = 1;

    while (y) {
        if (y & 1) res = res * x % mod;
        y >>= 1;
        x = x * x % mod;
    }

    return res;
}

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > g (n + 1);
    for (int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector <int> vis (n + 1, -1);

    int ok = 1;
    int ans = 1;
    for (int i = 1; i <= n; i ++) {
        if (vis[i] != -1) continue;
        
        queue <int> qu;   
        qu.push(i);
        vis[i] = 1;

        int cnt = 0, count = 0;
        while (qu.size()) {
            int x = qu.front(); qu.pop();

            count++;
            if (vis[x] == 1) cnt++;
            for (auto v : g[x]) {
                if (vis[v] == -1) {
                    vis[v] = (1LL ^ vis[x]);
                    qu.push(v);
                } else {
                    if (vis[v] == vis[x]) {
                        ok = 0;
                    }
                }
            }
        }

        ans = ans * ((qpow (2LL, count - cnt) + qpow (2LL, cnt)) % mod) % mod;
    }

    if (!ok) {
        cout << 0 << '\n';
        return;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}