
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m, k;
    cin >> n >> m >> k;

    vector <int> x (n + 1), y (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> x[i] >> y[i];
    }

    vector <int> l (n + 1, 0), h (n + 1, m + 1);

    for (int i = 1; i <= k; i ++) {
        int p;
        cin >> p >> l[p] >> h[p];
    }

    const int INF = 1e15;
    vector <vector <int> > dp (n + 1, vector <int> (m + 1, INF));

    for (int i = 0; i <= m; i ++) {
        dp[0][i] = 0;
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        // for (int j = 1; j <= m; j ++) {

            for (int k = x[i] + 1; k <= m + x[i]; k ++) {
                int to = min(k, m);
                int pre = k - x[i];
                dp[i][to] = min (dp[i][to], dp[i - 1][pre] + 1);
                dp[i][to] = min (dp[i][to], dp[i][pre] + 1);
            }

            for (int k = 1; k <= m - y[i]; k ++) {
                dp[i][k] = min (dp[i][k], dp[i - 1][k + y[i]]);
            }

            for (int k = 0; k <= l[i]; k ++) {
                dp[i][k] = INF;
            }

            for (int k = h[i]; k <= m; k ++) {
                dp[i][k] = INF;
            }

            
            bool ok = false;
            for (int j = 1; j <= m; j++) {
                if (dp[i][j] < INF) ok = true;
            }

            if (!ok) {
                cout << 0 << '\n' << cnt << '\n';
                return;
            }

            if (l[i] != 0 || h[i] != m + 1) cnt++;
        // }
    }

    int mn = INF; 
    for (int i = 1; i <= m; i ++) {
        mn = min (dp[n][i], mn);
    }

    cout << 1 << '\n' << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}