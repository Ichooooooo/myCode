#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;

    vector <vector <int> > a (n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    vector <int> ans (n + 1);
    for (int i = 1; i <= n; i ++) {
        vector <int> dp (m + 1);
        dp[1] = a[i][1] + 1;
        deque <arr2> dq;
        dq.push_back ({dp[1], 1});

        for (int j = 2; j <= m; j ++) {
            while (dq.size() && j - dq.front()[1] - 1 > d) {
                dq.pop_front();
            }

            if (dq.size()) {
                dp[j] = dq.front()[0] + a[i][j] + 1;
            }

            while (dq.size() && dq.back()[0] >= dp[j]) {
                dq.pop_back();
            }

            dq.push_back ({dp[j], j});
        }

        ans[i] = dp[m];
    }

    int bas = 0;
    for (int i = 1; i <= k; i ++) {
        bas += ans[i];
    }

    int an = bas;
    for (int i = k + 1; i <= n; i ++) {
        int now = bas + ans[i] - ans[i - k];
        an = min (an, now);

        bas = now;
    }

    cout << an << '\n';
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}