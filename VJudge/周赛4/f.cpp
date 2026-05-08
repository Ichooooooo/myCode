#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e15;

void ovo() {
    int n, k;
    cin >> n >> k;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <vector <int> > dp (k + 1, vector <int> (n + 1, -INF));
    dp[0][0] =0;

    for (int i = 1; i <= k; i ++) {
        for (int j = i; j <= (6 * i); j ++) {
            for (int k = 1; k <= min (j, 6LL); k ++) {
                dp[i][j] = max (dp[i][j], dp[i - 1][j - k] + a[j]);
            }
        }
    }

    int mx = -INF;
    for (int i = k; i <= 6 * k; i ++) {
        mx = max (mx, dp[k][i]);
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}