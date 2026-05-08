
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, k;
    cin >> n >> k;

    vector <int> a (n + 1), b (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    vector <arr2> dp (n + 1);
    // 0: biao
    dp[1][0] = a[1];
    const int INF = 1e15;
    dp[1][1] = -INF;

    for (int i = 2; i <= n; i ++) {
        dp[i][0] = dp[i - 1][0] + a[i];
        if (dp[i - 1][1] >= k) {
            dp[i][0] = max (dp[i][0], dp[i - 1][1] + a[i] - k);
        }
        dp[i][1] = dp[i - 1][1] + b[i];
        if (dp[i - 1][0] >= k) {
            dp[i][1] = max (dp[i][1], dp[i - 1][0] + b[i] - k);
        }       
    }

    cout << max (dp[n][0], dp[n][1]) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}