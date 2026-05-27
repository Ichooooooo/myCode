
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr4 = array <int, 4>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    const int INF = 1e6;
    vector <arr4> dp (n + 1, {INF, INF, INF, INF});

    if (a[1] == 1) {
        dp[1][3] = dp[1][2] = 1;
    } else {
        dp[1][3] = dp[1][2] = 0;
    }

    for (int i = 2; i <= n; i ++) {
        if (a[i] == 0) {
            dp[i][0] = min (dp[i - 1][2], dp[i - 1][3]);
            dp[i][1] = dp[i - 1][0];
            dp[i][2] = min (dp[i - 1][0], dp[i - 1][1]);
            dp[i][3] = dp[i - 1][2];            
        } else {
            dp[i][0] = min (dp[i - 1][2], dp[i - 1][3]);
            dp[i][1] = dp[i - 1][0];
            dp[i][2] = min (dp[i - 1][0], dp[i - 1][1]) + 1;
            dp[i][3] = dp[i - 1][2] + 1;
        }

        // cerr << "i : " << i << '\n';
        // cerr << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << ' ' << dp[i][3] << '\n';
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}