
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1), pre (n + 1);

    for (int i = 1; i<= n; i ++) {
        cin >> a[i];
        pre[i] = (pre[i - 1] ^ a[i]);
    }

    vector <vector <int> > mnp (n + 1, vector <int> (n + 1));

    for (int i = 1; i <= n; i ++) {
        int mn = pre[i];
        for (int j = 0; j <= i - 1; j ++) {
            mn = min(mn, (pre[i] ^ pre[j]));
            mnp[i][j] = mn;
        }
    }

    const int MX = 1e13;
    vector <int> dp (n + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = pre[i];
        for (int j = 0; j <= i - 1; j++) {
            dp[i] = min(dp[i], dp[j] + mnp[i][j]);
        }
    }

    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}