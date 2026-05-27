
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 105;
int a[N];
int b[N][N];
int dp[N][N][N];

void ovo() {
    int n, m, k; 
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> b[i][j];
        }
    }

    const int INF = 1e15;
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= k; j ++) {
            for (int k = 0; k <= m; k ++) {
                dp[i][j][k] = INF;
            }
        }
    }

    for (int i = 0; i <= m; i ++) {
        dp[0][0][i] = 0;
    }

    // if (a[1] != 0) {
    //     dp[1][1][a[1]] = 0;
    // } else {
    //     for (int i = 1; i <= m; i ++) {
    //         dp[1][1][i] = b[1][i];
    //     }
    // }

    for (int i = 1; i <= n; i ++) {

        cerr << "i : " << i << '\n';

        for (int j = 1; j <= k; j ++) {
            
            cerr << "j : " << j << '\n';

            if (a[i] != 0) {

                dp[i][j][a[i]] = min (dp[i][j][a[i]], dp[i - 1][j][a[i]]);

                cerr << "ori : " << dp[i][j][a[i]] << '\n';
                cerr << "ai : " << a[i] << '\n';
                for (int z = 1; z <= m; z ++) {
                    if (z == a[i]) continue;
                    dp[i][j][a[i]] = min (dp[i][j][a[i]], dp[i - 1][j - 1][z]);

                    cerr << "z : " << z << ' ' << dp[i][j][a[i]] << '\n';
                }
            } else {

                for (int k1 = 1; k1 <= m; k1 ++) {
                    dp[i][j][k1] = min (dp[i][j][k1], dp[i - 1][j][k1]) + b[i][k1];

                    for (int k2 = 1; k2 <= m; k2 ++) {
                        if (k1 == k2) continue;

                        dp[i][j][k1] = min (dp[i][j][k1], dp[i - 1][j - 1][k2] + b[i][k1]);
                    }

                    cerr << "k1 : " << k1 << ' ' << dp[i][j][k1] << '\n';
                }

            }
        }
    }

    int ans = INF;
    for (int i = 1; i <= m; i ++) {
        cerr << "i : " << i << ' '  << dp[n][k][i] << '\n';
        ans = min (ans, dp[n][k][i]);
    }

    if (ans >= INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}