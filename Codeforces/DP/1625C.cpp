
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, l, k;
    cin >> n >> l >> k;
    
    vector <int> d (n + 1), a (n + 1);
    for (int i = 0; i < n; i ++) {
        cin >> d[i];
    }

    d[n] = l;

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    const int INF = 1e10;
    vector <vector <int> > dp (n + 1, vector <int> (k + 1, INF));

    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= k; j ++) {
            for (int z = i - 1; z >= 0; z --) {
                int nm = i - z - 1;

                if (nm > j) break;
                
                dp[i][j] = min (dp[i][j], dp[z][j - nm] + a[z] * (d[i] - d[z]));
            }
        }
    }

    int ans = INF;

    for (int i = 0; i <= k; i ++) {
        ans = min (ans, dp[n][i]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}