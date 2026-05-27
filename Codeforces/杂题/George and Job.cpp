
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 5005;
int a[N], pre[N];
int dp[N][N];

void ovo() {
    int n, m, k;
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= k; j ++) {
            if (i - m < 0) continue;
            dp[i][j] = max (dp[i - 1][j], dp[i - m][j - 1] + pre[i] - pre[i - m]);

            // cerr << "i : " << i << ' ' << j << ' ' << dp[i][j] << '\n';
        }
    }

    cout << dp[n][k] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}