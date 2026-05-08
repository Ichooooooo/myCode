
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    string x, y;
    cin >> x >> y;

    const int INF = 1e15;
    vector <int> dp (n, INF);
    
    dp[0] = (x[0] != y[0]);
    for (int i = 1; i < n; i ++) {
        dp[i] = min (dp[i], dp[i - 1] + (x[i] != y[i]));
        if (i > 1) {
            dp[i] = min (dp[i], dp[i - 2] + (x[i] != x[i - 1]) + (y[i] != y[i - 1]));
        } else {
            dp[i] = min (dp[i], (int)((x[i] != x[i - 1]) + (y[i] != y[i - 1])));
        }
    }

    cout << dp[n - 1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}