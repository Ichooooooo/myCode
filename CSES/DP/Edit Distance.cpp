
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

const int N = 5005, INF = 1e5;
int dp[N][N];

void ovo() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            dp[i][j] = INF;
        }
    }
    
    for (int i = 0; i <= n; i ++) {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = min (dp[i][j], dp[i - 1][j - 1]);
                // cerr << "ijk : " << i << ' ' << j << ' ' << dp[i][j] << '\n';                
            }

            dp[i][j] = min ({dp[i][j], dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});

            // cerr << "ij : " << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }

    cout << dp[n][m] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}