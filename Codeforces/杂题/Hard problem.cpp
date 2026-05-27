
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <string> b (n + 1), c (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
        b[i] = c[i];
        reverse (c[i].begin(), c[i].end());
    }

    const int INF = 1e17;
    vector <arr2> dp (n + 1, {INF, INF});
    
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; i ++) {
        if (b[i] >= b[i - 1]) {
            dp[i][0] = dp[i - 1][0];
        } 
        if (b[i] >= c[i - 1]) {
            dp[i][0] = min (dp[i][0], dp[i - 1][1]);
        }
        if (c[i] >= b[i - 1]) {
            dp[i][1] = dp[i - 1][0] + a[i];
        }
        if (c[i] >= c[i - 1]) {
            dp[i][1] = min (dp[i][1], dp[i - 1][1] + a[i]);
        }

        // cerr << "i : " << i << '\n';
        // cerr << dp[i][0] << ' ' << dp[i][1] << '\n';
    }

    int ans = min (dp[n][0], dp[n][1]);
    if (ans >= INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}