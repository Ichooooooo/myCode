
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 405;
const int INF = 1e18;
int dp[N][N];

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 5), pre (n + 5);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = i; j <= n; j ++) {
            if (i == j) dp[i][j] = 0; 
            else dp[i][j] = INF;
        }
    }

    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l <= n - len + 1; l ++) {
            int r = l + len - 1;
            for (int k = l; k <= r - 1; k ++) {
                dp[l][r] = min (dp[l][r], dp[l][k] + dp[k + 1][r] + pre[k] - pre[l - 1] + pre[r] - pre[k]);
            }
        }
    }

    cout << dp[1][n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}