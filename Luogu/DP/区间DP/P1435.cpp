
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    string s; cin >> s;
    s = ' ' + s;
    int n = s.size() - 1;

    const int MX = 1e5;
    vector <vector <int> > dp (n + 1, vector <int> (n + 1));

    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l <= n - len + 1; l ++) {

            int r = l + len - 1;
            if (s[l] == s[r]) {
                dp[l][r] = dp[l + 1][r - 1];
            } else {
                dp[l][r] = min (dp[l][r - 1], dp[l + 1][r]) + 1;
            }
        }
    }

    cout << dp[1][n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}