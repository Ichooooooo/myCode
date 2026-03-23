
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 1e8;

void ovo() {
    int n, h; cin >> n >> h;

    vector <int> c (n), p (n);
    int mx = -1;
    for (int i = 0; i < n; i ++) {
        cin >> c[i] >> p[i];
        mx = max (mx, c[i]);
    }

    int m = h + mx;
    vector <int> dp (m + 1, N);
    dp[0] = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = c[i]; j <= m; j ++) {
            dp[j] = min (dp[j], dp[j - c[i]] + p[i]);
            // cerr << j << ' ' << dp[j] << '\n';
        }
    }

    int mn = N;
    for (int i = h; i <= m; i ++) {
        mn = min (mn, dp[i]);
    }

    cout << mn << '\n';

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}