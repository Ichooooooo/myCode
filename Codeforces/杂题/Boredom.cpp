
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    map <int, int> mp;
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        mp[x]++;
    }

    vector <int> a; 
    const int INF = 1e9;
    a.reserve (n + 5);a.push_back (INF);
    
    for (auto [x, y] : mp) {
        a.push_back (x);
    }

    int m = a.size();
    vector <arr2> dp (m + 1);

    for (int i = 1; i < m; i ++) {
        if (a[i] == a[i - 1] + 1) {
            dp[i][0] = dp[i - 1][1] + a[i] + (mp[a[i]] - 1) * a[i];
            dp[i][1] = max (dp[i - 1][0], dp[i - 1][1]);
        } else {
            dp[i][0] = max (dp[i - 1][0], dp[i - 1][1]) + a[i] + (mp[a[i]] - 1) * a[i];
            dp[i][1] = max (dp[i - 1][0], dp[i - 1][1]);
        }
    }

    cout << max (dp[m - 1][0], dp[m - 1][1]) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}