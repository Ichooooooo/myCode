#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <string> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector <vector <int> > dp (n, vector <int> (n));
    for (int i = 0; i < n; i ++) {
        if (a[0][i] == '*') break;
        dp[0][i] = 1;
    }

    for (int j = 0; j < n; j ++) {
        if (a[j][0] == '*') break;
        dp[j][0] = 1;
    }

    for (int i = 1; i < n; i ++) {
        for (int j = 1; j < n; j ++) {
            if (a[i][j] == '*') continue;

            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;

        }
    }

    cout << dp[n - 1][n - 1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}