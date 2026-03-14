
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    
    vector <int> a (n), dp (n + 1);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        dp[a[i]] = 1;
        // cout << a[i] << ' ' << dp[a[i]] << '\n';
    }

    ranges :: sort (a);
    a.erase(unique(a.begin(), a.end()), a.end());

    for (int i = 1; i <= n; i ++) {
        if (dp[i]) continue;
        int mn = LLONG_MAX;
        for (int j = 2; j * j <= i; j ++) {
            if (i % j == 0) {
                if (dp[i / j] && dp[j]) {
                    mn = min (mn, dp[i / j] + dp[j]);
                }
            }
        }

        if (mn == LLONG_MAX) continue;
        else dp[i] = mn;
    }

    for (int i = 1; i <= n; i ++) {
        if (dp[i]) cout << dp[i] << " \n"[i == n];
        else cout << -1 << " \n"[i == n];
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}