
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;

int qpow (int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void ovo() {
    int n; cin >> n;
    
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <arr2> b (n + 1);
    for (int i = 1; i <= n; i ++) {
        b[i][0] = b[i - 1][0] + a[i];
        b[i][1] = max (abs(b[i - 1][0] + a[i]), b[i - 1][1] + a[i]);
    }

    vector <arr2> dp (n + 1);
    dp[0][1] = dp[0][0] = 1;

    for (int i = 1; i <= n; i ++) {
        dp[i][0] = dp[i - 1][0];
        if (b[i - 1][0] + a[i] == abs (b[i - 1][0] + a[i])) dp[i][0] = (dp[i][0] + dp[i - 1][0]) % mod;
        
        if (b[i][1] == b[i - 1][1] + a[i]) {
            dp[i][1] = (dp[i][1] + 2 * dp[i - 1][1]) % mod;
        }

        if (b[i][1] == abs (b[i - 1][0] + a[i])) {
            if (b[i - 1][0] != b[i - 1][1])
                dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
            else {
                if (b[i - 1][0] + a[i] < 0) {
                    dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
                }
            }    
        }
    }

    cout << dp[n][1] << '\n';
}
signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}