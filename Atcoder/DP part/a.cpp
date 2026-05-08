
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> h (n + 1), dp (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> h[i];
    }

    dp[2] = abs (h[2] - h[1]);
    for (int i = 3; i <= n; i ++) {
        dp[i] = min (dp[i - 2] + abs (h[i] - h[i - 2]), dp[i - 1] + abs (h[i] - h[i - 1]));
    }

    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}