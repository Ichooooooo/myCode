
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m; 
    cin >> n >> m;
    
    vector <int> w (n), v (n);
    for (int i = 0; i < n; i ++) {
        cin >> w[i] >> v[i];
    }

    vector <int> dp (m + 1);
    for (int i = 0; i < n; i ++) {
        for (int j = m; j >= w[i]; j --) {
            dp[j] = max (dp[j], dp[j - w[i]] + v[i]);
        }
    }

    cout << dp[m] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}