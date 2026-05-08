
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e12;

void ovo() {
    int n, k; cin >> n >> k;
    vector <int> h (n + 1), dp (n + 1, INF);

    for (int i = 1; i <= n; i ++) {
        cin >> h[i];
    }

    dp[1] = 0;
    for (int i = 2; i <= n; i ++) {
        for (int j = 1; j <= k; j ++) {
            if (i - j < 1) break;
            dp[i] = min (dp[i], dp[i - j] + abs (h[i] - h[i - j]));
        }
    }

    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}