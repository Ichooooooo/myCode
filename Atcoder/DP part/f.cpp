
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector <vector <int> > dp (n, vector <int> (m));

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (s[i] == t[j]) {
                dp[i][j] = 1;
                if ((i - 1 >= 0 && j - 1 >= 0))
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            if (i - 1 >= 0) dp[i][j] = max (dp[i][j], dp[i - 1][j]);
            if (j - 1 >= 0) dp[i][j] = max (dp[i][j], dp[i][j - 1]);
        }
    }

    auto get = [&](int i, int j) -> int {
        if (i < 0 || j < 0) return 0;
        return dp[i][j];
    };

    string ss;
    int p1 = n - 1, p2 = m - 1;

    while (p1 >= 0 && p2 >= 0) {
        if (s[p1] == t[p2] && get(p1, p2) == get(p1 - 1, p2 - 1) + 1) {
            ss += s[p1];
            p1--;
            p2--;
        } else if (get(p1 - 1, p2) >= get(p1, p2 - 1)) {
            p1--;
        } else {
            p2--;
        }
    }

    reverse(ss.begin(), ss.end());
    cout << ss << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}