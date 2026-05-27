
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int M = 105;


void ovo() {
    string s; cin >> s;
    int d; cin >> d;
    
    int n = s.size();
    vector <int> a (n + 5);
    for (int i = 0; i < n; i ++) {
        a[i] = s[i] - '0';
        // cerr << "i : " << i << ' ' << a[i] << '\n';
    }

    vector <vector <int> > dp (n + 5, vector <int> (d + 5)), vis (n + 5, vector <int> (d + 5));
    
    auto dfs = [&] (auto self, int pos, int sum, bool tight) -> int {
        if (pos == n) return sum == 0;

        if (!tight && vis[pos][sum]) return dp[pos][sum];

        int up = (tight ? a[pos] : 9);

        int ans = 0;
        for (int i = 0; i <= up; i ++) {
            ans = (ans + self (self, pos + 1, (sum + d - i % d) % d, (tight && (i == up)))) % mod;
        }

        if (!tight && !vis[pos][sum]) {
            dp[pos][sum] = ans;
            vis[pos][sum] = 1;
        }

        return ans;
    };

    int ans = dfs(dfs, 0, 0, true);

    cout << (ans - 1 + mod) % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}