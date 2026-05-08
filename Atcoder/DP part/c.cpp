
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <arr3> a (n);
    for (auto &[x, y, z] : a) {
        cin >> x >> y >> z;
    }

    vector <arr3> dp (n);
    dp[0][0] = a[0][0], dp[0][1] = a[0][1], dp[0][2] = a[0][2];

    for (int i = 1; i < n; i ++) {
        dp[i][0] = max (dp[i - 1][1], dp[i - 1][2]) + a[i][0];
        dp[i][1] = max (dp[i - 1][0], dp[i - 1][2]) + a[i][1];
        dp[i][2] = max (dp[i - 1][0], dp[i - 1][1]) + a[i][2];

        // cerr << dp[i][2] << '\n';
    }

    cout << max ({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}