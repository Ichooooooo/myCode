
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int s, n, m;
    cin >> s >> n >> m;

    vector <vector <int> > a (n + 1, vector <int> (s + 1));
    for (int i = 1; i <= s; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> a[j][i];
        }
    }

    for (int i = 1; i <= n; i ++) {
        sort (a[i].begin() + 1, a[i].end());
    }

    vector <int> dp (m + 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = m; j >= 1; j --) {
            for (int k = 1; k <= s; k ++) {
                if (j - (2 * a[i][k] + 1) >= 0) {
                    dp[j] = max (dp[j], dp[j - (2 * a[i][k] + 1)] + k * i);
                }  else {
                    break;
                }
            }
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