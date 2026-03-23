
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int m, n; cin >> m >>  n;
    vector <int> p (n), c (n);
    for (int i = 0; i < n; i ++) {
        cin >> p [i] >> c[i];
    }

    vector <int> dp (m + 1);
    for (int i = 0; i < n; i ++) {
        for (int j = c[i]; j <= m; j ++) {
            dp[j] = max (dp[j], dp[j - c[i]] + p[i]);
        }
    }

    cout << ranges :: max (dp) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}