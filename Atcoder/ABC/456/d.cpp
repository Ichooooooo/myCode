
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr3 = array <int, 3>;
const int mod = 998244353;

void ovo() {
    string s; cin >> s;

    int n = s.size();
    vector <arr3> dp (n);

    for (int i = 0; i < n; i ++) {
        if (i == 0) {
            if (s[i] == 'a') dp[i][0]++;
            else if (s[i] == 'b') dp[i][1]++;
            else dp[i][2]++;
        } else {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1];
            dp[i][2] = dp[i - 1][2];

            if (s[i] == 'a') dp[i][0] = (dp[i][0] + (1 + dp[i - 1][1] + dp[i - 1][2]) % mod) % mod;
            else if (s[i] == 'b') dp[i][1] = (dp[i][1] + (1 + dp[i - 1][0] + dp[i - 1][2]) % mod) % mod;
            else dp[i][2] = (dp[i][2] + (1 + dp[i - 1][0] + dp[i - 1][1]) % mod) % mod;           
        }
    }

    cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % mod;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}