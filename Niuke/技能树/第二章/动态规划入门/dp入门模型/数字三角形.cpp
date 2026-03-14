#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    vector <vector <int>> a (n + 1, vector <int> (n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j ++) {
            cin >> a[i][j];
        }
    }

    vector <vector <int>> dp (n + 1, vector <int> (n + 1));
    dp[1][1] = a[1][1];

    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= i; j ++) {
            if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            } else if (j == 1) {
                dp[i][j] = dp[i - 1][j] + a[i][j];
                // wa点 : tamad这里有两个特判情况
            } else {
                dp[i][j] = max (dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
            }
        }
    }

    int ans = LLONG_MIN;
    for (int i = 1; i <= n; i ++) {
        ans = max (ans, dp[n][i]);
    }
    
    cout << ans << endl;
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