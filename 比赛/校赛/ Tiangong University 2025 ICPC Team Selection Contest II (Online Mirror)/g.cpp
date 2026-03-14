
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k, q;
    cin >> n >> k >> q;

    k = min (k, 50LL);
    vector <double> dp (n + 1);
    dp[1] = 1;
    for (int i = 0; i < k; i ++) {
        vector <double> ndp(n + 1);
        for (int j = 1; j <= n; j ++) {
            ndp[j] = dp[j] / (n - j + 1);
            if (j != 1) ndp[j] += ndp[j - 1]; 
        }
        dp = move(ndp);
    }

    int x;
    while (q --) {
        cin >> x;
        cout << fixed << setprecision(8) << dp[x] << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}