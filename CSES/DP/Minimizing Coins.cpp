#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n, x; cin >> n >> x;

    const int INF = 1e15;
    vector <int> dp (x + 1, INF);
    vector <int> a (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    dp[0] = 0;
    
    for (int i = 1; i <= x; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (i - a[j] >= 0) {
                dp[i] = min (dp[i], dp[i - a[j]] + 1);
            }
        }
    }

    if (dp[x] == INF) {
        cout << -1 << '\n';
    } else {
        cout << dp[x] << '\n';
    }
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}