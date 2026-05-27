
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 30;
int a[N][N];

void ovo() {
    int n; cin >> n;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
        }
    }

    int m = (1LL << n);
    vector <vector <int> > dp (n + 1, vector <int> (m));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++) {
        // cerr << "i : " << i << '\n';
        for (int j = 0; j < n; j ++) {
            if (a[i - 1][j] == 0) continue;

            for (int k = 0; k < m; k ++) {
                if (!(k & (1LL << j))) continue;
                
                dp[i][k] = (dp[i - 1][k - (1LL << j)] + dp[i][k]) % mod;
                // cerr << "j : " << j << ' ' << k << ' ' << dp[i][k] << '\n';
            }
        }
    }

    cout << dp[n][(1LL << n) - 1] << '\n';
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}