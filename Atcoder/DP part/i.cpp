
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
#define double long double

void ovo() {
    int n; cin>> n;
    vector <double> p (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
    }

    vector <vector <double> > dp (n + 1, vector <double> (n + 1));

    dp[1][0] = (1 - p[1]);
    dp[1][1] = p[1];

    for (int i = 2; i <= n; i ++) {
        for (int j = 0; j <= i; j ++) {
            dp[i][j] = dp[i - 1][j] * (1 - p[i]);
            if (j - 1 >= 0) dp[i][j] += dp[i - 1][j - 1] * p[i];
        }
    }

    double ans = 0;
    for (int i = (n + 1) / 2; i <= n; i ++) {
        ans += dp[n][i];
    }

    cout << fixed << setprecision(12) << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}