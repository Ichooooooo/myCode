#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m;  cin >> n >> m;

    vector <vector <int>> dp (n + 1, vector <int> (m + 1, 1));

    for (int i = 2; i <= n; i ++) {
        for (int j = 2; j <= m; j ++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            // wa点 : 加法没有分步取模
        }
    }

    cout << dp[n][m] % mod << endl;
}

void solve2() {
    int n, m;
    cin >> n >> m;

    // dp[j] 表示当前行的 dp[i][j]
    vector<long long> dp(m + 1, 1); 
    // 初始化：第一行全 1；之后每一行的第一列也保持 1

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            dp[j] = (dp[j] + dp[j - 1]) % mod; // dp[j] 原本是上方 dp[i-1][j]
        }
    }

    cout << dp[m] % mod << "\n";
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