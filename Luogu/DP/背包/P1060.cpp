
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m; cin >> m >> n;
    vector <int> c (n), p (n);

    for (int i = 0; i < n; i ++) {
        int x, y; cin >> x >> y;
        c[i] = x;
        p[i] = x * y;
    }

    vector <int> dp (m + 1);
    for (int i = 0; i < n; i ++) {
        for (int j = m; j >= c[i]; j --) {
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