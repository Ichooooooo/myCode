#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1, vector<int> (n + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            if (i == 1) dp[i][j] = a[i][j];
            else {
                if (j - 1 >= 1) {
                    dp[i][j] = a[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
                } else {
                    dp[i][j] = a[i][j] + dp[i - 1][j];
                }
            }
        }
    }

    ll mx = -1;
    for (int j = 1; j <= n; j ++) {
        mx = max(mx, dp[n][j]);
    }

    cout << mx << endl;
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