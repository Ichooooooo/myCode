
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    vector <vector <int> > dp (n + 5, vector <int> (n + 5));

    dp[1][1] = 1;
    for (int i = 2; i <= n; i ++) {
        if (s[i - 1 - 1] == '>') {
            for (int j = i; j >= 1; j --) {
                dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
            }
        } else {
            for (int j = 1; j <= i; j ++) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = (ans + dp[n][i]) % mod;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}