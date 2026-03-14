
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <int> a (n + 1), b (n + 1);
    for (int i = 1; i <= n; i ++)  cin >> a[i];
    for (int j = 1; j <= n; j ++)  cin >> b[j];

    // int mx = 0;
    // for (int bit = 0; bit <= 11; bit ++) mx += (1 << bit);
    // cout << mx << endl;
    vector <array<int, 4096>> dp (n + 2);
    dp[0][0] = 1; int m = 4095;
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            if (dp[i][j]) {
                int x1 = max (0LL, j - a[i]), x2 = (j ^ b[i]);
                dp[i + 1][x1] = 1; dp[i + 1][x2] = 1;
                // cout << x1 << ' ' << x2 << '\n';
            } 
        }
    } 

    int ans = 0;
    for (int i = 0; i <= m; i ++) {
        if (dp[n + 1][i]) {
            ans = max (ans, i); 
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}