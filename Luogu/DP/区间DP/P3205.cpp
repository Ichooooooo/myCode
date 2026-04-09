
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 19650827;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <vector <array <int, 2> > > dp (n + 1, vector <array <int, 2> > (n + 1));

    for (int i = 1; i <= n; i ++) {
        dp[i][i][0] = 1;
        dp[i][i][1] = 0;
    }

    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l <= n - len + 1; l ++) {
            int r = l + len - 1;

            if (a[l] < a[l + 1]) dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][0]) % mod;
            if (a[l] < a[r]) dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][1]) % mod;
            if (a[r] > a[r - 1]) dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][1]) % mod;
            if (a[r] > a[l]) dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][0]) % mod; 
        }
    }

    cout << (dp[1][n][1] + dp[1][n][0]) % mod << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}