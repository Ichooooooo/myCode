#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int x; cin >> x;
    vector <int> dp (x + 1);

    dp[0] = 1;
    for (int i = 1; i <= x; i ++) {
        for (int j = 1; j <= 6; j ++) {
            if (i - j < 0) break;
            dp[i] = (dp[i] + dp[i - j]) % mod;
        }

        // cerr << dp[i] << '\n';
    }

    cout << dp[x] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}