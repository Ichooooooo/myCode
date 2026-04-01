
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> p (n), w (n - 1);
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
    }

    for (int i = 0; i < n - 1; i++) {
        cin >> w[i];
    }

    const int MN = -(1LL << 60);
    int full = (1LL << n);
    vector <vector <int>> dp (full, vector <int> (n, MN));
    for (int i = 0; i < n; i ++) {
        dp[(1LL << i)][i] = 0;
    }

    auto cal = [&](int x) -> int {
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            if ((x >> i) & 1) cnt++;
        }

        return cnt;
    };

    // 哪些被用
    for (int i = 0; i < full; i ++) {
        // 最后是什么
        int cnt = cal (i);

        for (int j = 0; j < n; j ++) {
            if (!((i >> j) & 1LL)) continue;
            // 下一个加上谁
            for (int k = 0; k < n; k ++) {
                if ((i >> k) & 1LL) continue;

                int add = abs (p[k] - p[j]) * w[cnt - 1];
                dp[i + (1LL << k)][k] = max (dp[i + (1LL << k)][k], dp[i][j] + add);
            }
        }
    }

    cout << *max_element(dp[full - 1].begin(), dp[full - 1].end()) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}