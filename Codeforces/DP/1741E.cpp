
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> b (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    vector <int> dp (n + 1);
    dp[0] = 1;

    for (int i = 0; i <= n; i ++) {
        // cerr << "i : " << i << '\n';

        int x1 = b[i];
        int t1 = i - x1 - 1;
        if (t1 >= 0) dp[i] |= dp[t1];

        // cerr << "x1 : " << x1 << ' ' << t1 << ' ' << dp[i] << '\n';
        if (i == n) continue;
        int x2 = b[i + 1];
        int t2 = i + 1 + x2;
        if (t2 <= n) dp[t2] |= dp[i];

        // cerr << "x2 : " << x2 << ' ' << t2 << ' ' << dp[t2] << '\n';
    }

    if (dp[n]) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}