
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int s, n, d;
    cin >> s >> n >> d;
    
    vector <int> c (d), p (d);
    for (int i = 0; i < d; i ++) {
        cin >> c[i] >> p[i];
        c[i] /= 1000;
    }

    int ans = s;
    vector <int> dp;
    for (int i = 1; i <= n; i ++) {
        int now = ans / 1000;
        dp.assign (now + 1, 0);
        for (int j = 0; j < d; j ++) {
            for (int k = c[j]; k <= now; k ++) {
                dp[k] = max (dp[k], dp[k - c[j]] + p[j]);
            }
        }

        int mx = ranges :: max (dp);
        ans += mx;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}