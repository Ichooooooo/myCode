
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, x; cin >> n >> x;

    vector <int> c (n), p (n);
    for (int & i : c) cin >> i;
    for (int & i : p) cin >> i;

    vector <vector <int>> dp (x + 1, vector <int> (3, LLONG_MIN));
    dp[0][0] = 0;
    // 0: bumai, 1 : yuanjia, 2 : banjia
    for (int i = 0; i < n; i ++) {
        vector <vector <int>> ndp (x + 1, vector <int> (3, LLONG_MIN));
        ndp[0][0] = 0;
        for (int j = x; j >= 0; j --) {
            if (j >= c[i]) {
                ndp[j][0] = max ({dp[j][0], dp[j][1], dp[j][2]});
                ndp[j][1] = max ({dp[j - c[i]][0] + p[i], dp[j - c[i]][1] + p[i], dp[j - c[i]][2] + p[i]});
                ndp[j][2] = dp[j - c[i] / 2][1] + p[i];
            } else if (j < c[i] && j >= c[i] / 2) {
                ndp[j][0] = max ({dp[j][0], dp[j][1], dp[j][2]});
                ndp[j][2] = dp[j - c[i] / 2][1] + p[i];
            } else {    
               ndp[j][0] = max ({dp[j][0], dp[j][1], dp[j][2]});
            }
        }
        dp = move(ndp);
    }

    int mx = 0;
    for (int i = x; i >= 0; i --) {
        mx = max ({mx, dp[i][0], dp[i][1], dp[i][2]});
        // cout << i << ' ' <<  mx << '\n';
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}