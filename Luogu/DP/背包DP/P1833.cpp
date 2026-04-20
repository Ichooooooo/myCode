#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    string s1, s2; int n;
    cin >> s1 >> s2 >> n;

    int m = (stol (s2.substr(0, s2.find(':'))) - stol (s1.substr(0, s1.find(':')))) * 60;
    m = m + (stol (s2.substr(s2.find(':') + 1)) - stol (s1.substr(s1.find(':') + 1)));

    // cerr << "m : " << m << '\n';

    vector <vector <int> > dp (n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i ++) {
        int t, c, p;
        cin >> t >> c >> p;

        // cerr << "i : " << i << '\n';

        if (p == 0) {
            for (int j = 0; j <= m; j ++) {
                if (j < t) dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = max ({dp[i - 1][j], dp[i - 1][j - t] + c, dp[i][j - t] + c});
                }

                // cerr << j << ' ' << dp[i][j] << '\n';
            }
        } else {
            for (int j = 1; j <= p; j ++) {
                int x = j * t;
                int y = j * c;
                // cerr << "j : " << j << '\n';
                // cerr << "xy : " << x << ' ' << y << '\n';
                for (int k = 0; k <= m; k ++) {
                    if (k < x) dp[i][k] = max (dp[i][k], dp[i - 1][k]);
                    else dp[i][k] = max ({dp[i][k], dp[i - 1][k], dp[i - 1][k - x] + y});

                    // cerr << k << ' ' << dp[i][k] << '\n';
                }
            }
        }
    }

    cout << dp[n][m] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}