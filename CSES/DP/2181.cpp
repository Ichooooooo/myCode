
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > dp (m + 1, vector <int> (1LL << n));
    dp[0][0] = 1;

    auto dfs = [&] (auto self, int row, int mask, int nmask, int col) -> void {
        if (row == n) {
            dp[col + 1][nmask] = (dp[col + 1][nmask] + dp[col][mask]) % mod;
            return;
        }

        if (mask & (1LL << row)) {
            self (self, row + 1, mask, nmask, col);
            return;
        }

        self (self, row + 1, mask, nmask | (1LL << row), col);

        if (row + 1 < n && !(mask & (1LL << (row + 1)))) {
            self (self, row + 2, mask, nmask, col);
        }
    };

    for (int col = 0; col < m; col ++) {
        for (int mask = 0; mask < (1LL << n); mask ++) {
            if (dp[col][mask]) {
                dfs (dfs, 0, mask, 0, col);
            }
        }
    }

    cout << dp[m][0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}