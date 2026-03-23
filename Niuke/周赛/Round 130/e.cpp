#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    string s; cin >> s;
    int n = s.size();

    int ans = 2e5;
    for (int d = 0; d <= 13; d ++) {
        vector <int> dp(26, 1);
        dp[s[0] - 'a'] = 0;

        for (int i = 1; i < n; i ++) {
            int t = s[i] - 'a';
            vector <int> dp2(26, 2e5);
            for (int j = 0; j < 26; j ++) {
                dp2[j] = min (dp2[j], dp[(j - d + 26) % 26] + (t != j));
                dp2[j] = min (dp2[j], dp[(j + d) % 26] + (t != j));
            }

            swap (dp, dp2);
        }

        int mn = ranges :: min (dp);
        ans = min (ans, mn);
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}