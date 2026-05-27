
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (n);
    int ans = 0;

    cin >> a[1];
    ans = n * a[1];
    for (int i = 2; i < n; i ++) {
        cin >> a[i];
        a[i] -= a[1];
    }

    const int INF = 1e15;
    vector <int> dp (n - 2 + 1, -INF);
    dp[0] = 0;
    for (int i = 1; i <= n - 2; i ++) {
        for (int j = i; j <= n - 2; j ++) {
            dp[j] = max (dp[j], dp[j - i] + a[i + 1]);
        }
    }

    cout << ans + dp[n - 2] << '\n'; 
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}