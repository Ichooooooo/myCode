
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e7;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <arr2> dp (n + 1);
    vector <int> mxx (n + 1, -INF);

    for (int i = 1; i <= n; i ++) {
        dp[i][1] = max (dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = mxx[a[i]] + i + 1;
        mxx[a[i]] = max (mxx[a[i]], dp[i][1] - i);
    }

    cout << max (dp[n][0], dp[n][1]) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}