
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, w;
    cin >> n >> w;
    vector <int> a (n);
    for (int & i : a) cin >> i;

    int full = (1LL << n);
    const int MX = 100;

    vector <vector <int>> dp (n + 1, vector <int> (full, -1));
    
    for (int j = 0; j < n; j ++) {
        dp[1][(1LL << j)] = w - a[j];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < full; j ++) {
            if (dp[i][j] == -1) continue;
            
            for (int k = 0; k < n; k ++) {
                if ((j >> k) & 1) continue;
                if (dp[i][j] >= a[k]) {
                    dp[i][j + (1LL << k)] = max(dp[i][j + (1LL << k)], dp[i][j] - a[k]);
                } else {
                    dp[i + 1][j + (1LL << k)] = max(dp[i + 1][j + (1LL << k)], w - a[k]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dp[i][full - 1] != -1) {
            cout << i << '\n';
            return;
        }
    }

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}