#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

int a[110][110];
int dp[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

int dfs (int i, int j) {

    if (dp[i][j]) return dp[i][j];

    dp[i][j] = 1;
    for (int k = 0; k < 4; k ++) {
        int tx = i + dx[k];
        int ty = j + dy[k];
        if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if (a[tx][ty] < a[i][j]) {
            dp[i][j] = max(dp[i][j], dfs(tx, ty) + 1);
        }
    }
    return dp[i][j];
}

void solve(){   
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            ans = max(ans, dfs(i, j));
        }
    }
    cout << ans << endl;
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