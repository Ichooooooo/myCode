#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int n;  cin >> n;
    vector <int> a (n + 1), pr (n + 1);

    int ps = 0;
    for (int i = 1; i <= n; i ++)  {
        cin >> a[i];
        pr[i] = ps;
        if (a[i] > 0) ps = i;
    }

    vector <int> dp (n + 2), s (n + 2);

    dp[1] = 1, s[1] = 1;
    for (int i = 1; i <= n; i ++) {
        int j = i;     
        int sum = 0, h = 0;

        while (j > 0 && sum + a[j] == (h | a[j])) {
            sum += a[j];
            h |= a[j];
            j = pr[j];
        }

         dp[i + 1] = (s[i] - s[j]) % mod;
        // if (dp[i + 1] < 0) dp[i + 1] += mod;
        s[i + 1] = s[i] + dp[i + 1];
        // if (s[i + 1] >= mod) s[i + 1] -= mod;
    }

    cout << dp[n + 1] << endl;

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}