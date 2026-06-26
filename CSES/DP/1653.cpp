
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, full;
    cin >> n >> full;

    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int m = (1LL << n);
    const int N = 30;
    const int INF = 1e10;
    vector <arr2> dp (m, {N, INF});

    dp[0] = {0, INF};
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            auto [x, y] = dp[i];
            if (y + a[j] <= full) 
            dp[i | (1LL << j)] = min (dp[i | (1LL << j)], {x, y + a[j]});
            else 
            dp[i | (1LL << j)] = min (dp[i | (1LL << j)], {x + 1, a[j]});
        }
    }
    
    auto [x, y] = dp[m - 1];
    cout << x << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}