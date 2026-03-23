
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m;
    cin >> n >> m;
    vector <string> a (n);
    for (string & i : a) cin >> i;
    
    vector <int> num (m);
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (a[j][i] == '0') num[i] ++;
        }
    }

    for (int i = 0; i < n; i ++) {
        int ans = 0;
        vector <int> dp (m);
        int to = 0;
        for (int j = 0; j < m; j ++) {
            int dif = 0;
            if (a[i][j] == '0') dif = n - num[j];
            else dif = num[j];
            to += dif;
            
            // cout << dif << ' ';
            int ch = dif - (n - dif - 1);
            // cout << ch << '\n';
            if (j == 0) dp[j] = ch;
            else dp[j] = max (dp[j - 1] + ch, ch);
        }

        int mx = ranges :: max (dp);
        // cout << to << ' ' << mx << '\n';
        if (mx > 0) ans = (to - mx);
        else ans = to;
        
        cout << ans << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}