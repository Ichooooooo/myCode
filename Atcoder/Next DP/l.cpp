
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1), dp (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    dp[1] = 1;
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= i - 1; j ++) {
            dp[i] = (dp[i] + dp[j] * lcm (a[i], a[j]) % mod) % mod;
        }
    }

    for (int i = 2; i <= n; i ++) {
        cout << dp[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}