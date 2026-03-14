#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int  n, m;
    cin >> n >> m;
    
    vector<vector<int>> dp(m + 1, vector<int> (n + 1));
    dp[0][1] = 1;
    for (int i = 1; i <= m; i ++) {
        for (int j = 1; j <= n; j ++) {
            dp[i][j] = dp[i - 1][(j - 1 + n - 1) % n + 1] + dp[i - 1][j % n + 1];
        }
    }
    cout << dp[m][1] << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}