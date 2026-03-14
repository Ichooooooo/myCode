#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;

    vector <int> dp (n + 1, 1);
    for (int i = 2; i <= n; i ++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
    // wa点 : tamad小红从1级阶梯开始

    cout << dp[n] << endl;
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