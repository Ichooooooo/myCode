
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e16;

void ovo() {
    int n, k; 
    cin >> n >> k;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <arr2> dp (n + 1);
    dp[1][0] = INF;
    dp[1][1] = a[1];
    for (int i = 2; i <= n; i ++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = min (dp[i - 1][1], dp[i - 1][0]) + a[i];

        cerr << "i : " << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
    }

    int mn = 0;
    for (int i = 1; i <= n - k + 1; i ++) {
        mn = min (mn, dp[i + k - 1][1] - dp[i - 1][1]);
        if (i + k + 1 - 1 <= n) {
            mn = min (mn, dp[i + k + 1 - 1][1] - dp[i - 1][1]);
        }
        if (i + k + 2 - 1 <= n) {
            mn = min (mn, dp[i + k + 2 - 1][1] - dp[i - 1][1]);
        }
        if (i + k + 3 - 1 <= n) {
            mn = min (mn, dp[i + k + 3 - 1][1] - dp[i - 1][1]);
        }
    }

    cout << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}