
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int m, t; cin >> t >> m;
    vector <int> c (m), p (m);
    for (int i = 0;i < m; i ++) {
        cin >> c[i] >> p[i];
    }

    vector <int> dp (t + 1);
    for (int i = 0; i < m; i ++) {
        for (int j = t; j >= c[i]; j --) {
            dp[j] = max (dp[j], dp[j - c[i]] + p[i]);
        }
    }

    cout << dp[t] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}