
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr3= array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <arr3> dp (n + 1);
    // 0 : xiuxi 1 : contest
    for (int i = 1; i <= n; i ++) {
        dp[i][0] = max ({dp[i - 1][1], dp[i - 1][2], dp[i - 1][0]});

        if (a[i] == 3) {
            dp[i][1] = max (dp[i - 1][2] + 1, dp[i - 1][0] + 1);
            dp[i][2] = max (dp[i - 1][1] + 1, dp[i - 1][0] + 1);
        } else if (a[i] == 1) {
            dp[i][1] = max (dp[i - 1][0] + 1, dp[i - 1][2] + 1);
            dp[i][2] = max (dp[i - 1][0], dp[i - 1][1]);
        } else if (a[i] == 2) {
            dp[i][2] = max (dp[i - 1][0] + 1, dp[i - 1][1] + 1);
            dp[i][1] = max (dp[i - 1][2], dp[i - 1][0]);
        } else {
            dp[i][1] = max (dp[i - 1][2], dp[i - 1][0]);
            dp[i][2] = max (dp[i - 1][0], dp[i - 1][1]);
        }
    }

    cout << n - max ({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}