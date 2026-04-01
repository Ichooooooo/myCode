
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, k, t, c;
    cin >> n >> k >> t >> c;

    vector <int> a (n + 1);
    vector <int> dp (n + 1);

    int ans = 0, now = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        now += dp[i];
        if (a[i] + now < t) {
            int ch = t - a[i] - now;
            ans += ch;
            if (i + k <= n) {
                dp[i + k] -= ch;
            }
            now += ch;
        }
    }

    cout << ans * c << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}