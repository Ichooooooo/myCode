#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;

int qpow (int a, int b, int m)//a的b次方
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1), deg (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        deg[a[i]]++;
    }

    queue <int> qu;
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (deg[i] == 0) {
            qu.push(i);
            cnt++;
        }
    }

    while (qu.size()) {
        auto u = qu.front(); qu.pop();
        if (!(--deg[a[u]])) {
            cnt++;
            qu.push(a[u]);
        }
    }

    int ans = qpow (25, cnt, mod);

    vector <int> vis (n + 1);
    for (int i = 1; i <= n; i ++) {
        if (!deg[i] || vis[i]) continue;

        int u = i, len = 0;
        while (!vis[u]) {
            len ++;
            vis[u] = 1;
            u = a[u];
        }

        ans = (ans * ((qpow (25, len, mod) + (qpow (-1, len, mod) * (25))) % mod)) % mod;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}