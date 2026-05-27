// 坑点 : 回溯路径的时候, 应该保证两个条件同时成立a[x] == b[y] && dp[x][y] == dp[x - 1][y - 1] + 1
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 1005;
int a[N], b[N];
int dp[N][N];

void ovo() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    } 

    for (int j = 1; j <= m; j ++) {
        cin >> b[j];
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (a[i] == b[j]) {
                dp[i][j] = max (dp[i][j], dp[i - 1][j - 1] + 1);
            }

            dp[i][j] = max ({dp[i][j], dp[i - 1][j], dp[i][j - 1]});
        }
    }

    cout << dp[n][m] << '\n';

    vector <int> ans;
    
    int x = n, y = m;
    while (x >= 1 && y >= 1) {
        if (a[x] == b[y] && dp[x][y] == dp[x - 1][y - 1] + 1) {
            ans.push_back (a[x]);
            x--;
            y--;
        } else if (dp[x][y] == dp[x - 1][y]) {
            x--;
        } else if (dp[x][y] == dp[x][y - 1]) {
            y--;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i --) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}