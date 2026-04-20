#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, x;
    cin >> n >> x;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    const int INF = 1e15;
    vector <int> dp (x + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i ++) {
        
        // cerr << i << ": " << '\n';
        for (int j = a[i]; j <= x; j ++) {

            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
            // cerr << "j : " << j << ": " << dp[j] << '\n';
        }
        
    }

    cout << dp[x] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}