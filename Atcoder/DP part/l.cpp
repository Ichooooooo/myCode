
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;
const int N = 3005;
int dp[N][N];

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++) {
        dp[i][i] = a[i];
    }

    for (int len = 2; len <= n; len ++) {
        for (int l = 1; l <= n - len + 1; l ++) {
            int r = l + len - 1;
            dp[l][r] = max (a[l] - dp[l + 1][r], a[r] - dp[l][r - 1]);
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