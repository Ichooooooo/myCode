
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, M, T;
    cin >> n >> M >> T;

    vector <vector <int> > dp (M + 1, vector <int> (T + 1));
    for (int i = 0; i < n; i ++) {
        int m, t; 
        cin >> m >> t;

        for (int j = M; j >= m; j --) {
            for (int k = T; k >= t; k --) {
                dp[j][k] = max (dp[j - m][k - t] + 1, dp[j][k]);
            }
        }
    }

    cout << dp[M][T];
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}