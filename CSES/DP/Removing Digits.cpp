#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n; cin >> n;

    const int INF = 1e15;
    vector <int> dp (n + 1, INF);
    
    dp[0] = 0;
    for (int i = 1; i <= n; i ++) {
        string t = to_string (i);

        for (int j = 0; j < t.size(); j ++) {
            dp[i] = min (dp[i], dp[i - (t[j] - '0')] + 1);
        }

        // cerr << i << ' ' << dp[i] << '\n';
    }

    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}