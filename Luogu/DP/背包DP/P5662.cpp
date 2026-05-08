
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 1e4 + 10;

void ovo() {
    int t, n, m;
    cin >> t >> n >> m;

    vector <vector <int> > a (t + 1, vector <int> (n + 1));
    for (int i = 1; i <= t; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }

    vector <int> dp (N);
    int now = m;
    for (int i = 1; i <= t - 1; i ++) {
        for (int j = 0; j <= now; j ++) {
            dp[j] = 0;
        }

        for (int j = 1; j <= n; j ++) {
            for (int k = a[i][j]; k <= now; k ++) {
                dp[k] = max (dp[k], dp[k - a[i][j]] + (a[i + 1][j] - a[i][j]));
            }
        }

        now += dp[now];
    }

    cout << now << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}