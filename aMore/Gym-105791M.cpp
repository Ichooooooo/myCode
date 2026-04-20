#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <vector <int> > v(n, vector <int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    int m = (1LL << n);
    vector <vector <i64> > dp(m, vector <i64> (n, 1e18));

    dp[1][0] = 0;
    for (i64 mask = 1; mask < m; mask += 2) {
        for (int j = 0; j < n; j++) {
            if ((mask >> j & 1) == 0) continue;
            i64 pre = mask ^ (1 << j);
            if (pre == 0) continue;
            for (int k = 0; k < n; k++) {
                if ((pre >> k & 1) == 0) continue;
                dp[mask][j] = min(dp[mask][j], dp[pre][k] + v[k][j]);
            }
        }
    }

    i64 ans = 1e18;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[m - 1][i] + v[i][0]);
    }

    cout << ans << '\n';
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}