#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    string s;  cin >> s;

    vector <array<int, 3>> dp(n + 1);
    // s0, r1, p2
    for (int i = 1; i <= n; i ++) {
        if (s[i - 1] == 'S') {
            dp[i][0] = max (dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = max (dp[i - 1][2], dp[i - 1][0]) + 1;
            dp[i][2] = -1;
        } else if (s[i - 1] == 'R') {
            dp[i][1] = max (dp[i - 1][0], dp[i - 1][2]);
            dp[i][0] = -1;
            dp[i][2] = max (dp[i - 1][0], dp[i - 1][1]) + 1;
        } else {
            dp[i][2] = max (dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = -1;
            dp[i][0] = max (dp[i - 1][1], dp[i - 1][2]) + 1;
        }
        // cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << endl;
    }

    cout << max (dp[n][0], max (dp[n][1], dp[n][2])) << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}