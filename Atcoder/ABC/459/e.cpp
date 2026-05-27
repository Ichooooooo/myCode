
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;

const int N = 1e6 + 5;
int f[N], g[N];

int qpow (int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv (int x) {
    return qpow (x, mod - 2);
}

int C (int n, int m) {
    int ans = g[m];
    for (int i = 1; i <= m; i ++) {
        ans = ans * ((n - i + 1) % mod) % mod;
    }

    return ans;
}

void ovo() {
    int n; cin >> n;

    f[0] = 1;
    for (int i = 1; i < N; i ++) {
        f[i] = f[i - 1] * i % mod;
    }

    g[N - 1] = inv (f[N - 1]);

    for (int i = N - 2; i >= 1; i --) {
        g[i] = g[i + 1] * (i + 1) % mod; 
    }

    vector <int> p (n + 1);
    vector <vector <int> > gg (n + 1);
    for (int i = 2; i <= n; i ++) {
        cin >> p[i];
        gg[p[i]].push_back(i);
    }

    // for (int i = 1; i <= n; i ++) {
    //     cerr << "i : " << i << '\n';
    //     for (auto v : gg[i]) {
    //         cerr << v << ' ';
    //     }
    //     cerr << '\n';
    // }

    vector <int> c (n + 1), d (n + 1), nm (n + 1), dem (n + 1);
    // 糖果, 1e9
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
    }
    // 松鼠, 1e6
    for (int i = 1; i <= n; i ++) {
        cin >> d[i];
    }

    auto dfs0 = [&] (auto self, int u) -> int {
        int cnm = c[u];
        for (auto v : gg[u]) {
            cnm += self (self, v);
        }

        nm[u] = cnm;
        // cerr << "u : " << u << ' ' << nm[u] << '\n';
        
        return nm[u];
    };

    auto dfs1 = [&] (auto self, int u) -> int {
        int cdem = d[u];
        for (auto v : gg[u]) {
            cdem += self (self, v);
        }

        dem[u] = cdem;
        // cerr << "u : " << u << ' ' << nm[u] << '\n';
        
        return dem[u];
    }; 

    dfs0(dfs0, 1);
    dfs1(dfs1, 1);

    vector <int> dp (n + 1);
    bool ok = true;
    
    auto dfs2 = [&] (auto self, int u) -> int {

        if (!ok) return 0;

        int x = 1, alld = 0;
        for (auto v : gg[u]) {
            alld += dem[v];
            x = x * self (self, v) % mod;

            if (!ok) return 0;
        }

        if (nm[u] < alld + d[u]) {
            ok = false;
            return 0;
        }

        dp[u] = x * C (nm[u] - alld, d[u]) % mod;

        return dp[u];
    };

    dfs2 (dfs2, 1);

    if (!ok) {
        cout << 0 << '\n';
    } else {
        cout << dp[1] << '\n';
    }   
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}