
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr4 = array <int, 4>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    string ss = "hard";
    const int INF = 1e16;
    vector <arr4> dp (n + 1, {INF, INF, INF, INF});
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++) {

        for (int j = 0; j < 4; j ++) {
            if (dp[i - 1][j] == INF) continue;

            dp[i][j] = min (dp[i][j], dp[i - 1][j] + a[i]);
            
            if (s[i - 1] == ss[j]) {
                if (j + 1 < 4) {
                    dp[i][j + 1] = min (dp[i][j + 1], dp[i - 1][j]);
                }
            } else {
                 dp[i][j] = min (dp[i][j], dp[i - 1][j]);
            }
        }
    }

    cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]}) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}