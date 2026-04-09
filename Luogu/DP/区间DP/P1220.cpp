    #include <bits/stdc++.h>
    #define int long long
    using namespace std;

    void ovo() {
        int n, c; cin >> n >> c;
        vector <int> a (n + 1), b (n + 1), pre (n + 1);

        for (int i = 1; i <= n; i ++) {
            cin >> a[i] >> b[i];
            pre[i] = pre[i - 1] + b[i];
        }

        const int INF = 1e15;
        vector <vector <array <int, 2> >> dp (n + 1, vector <array <int, 2> > (n + 1, {INF, INF}));

        auto cal = [&] (int l, int r, int x, int y) -> int {
            return (pre[n] - pre[r] + pre[l - 1]) * abs (a[y] - a[x]);
        };


        dp[c][c][0] = dp[c][c][1] = 0;

        // // 只往左扩
        for (int i = c - 1; i >= 1; --i) {
            dp[i][c][0] = dp[i + 1][c][0] + cal(i + 1, c, i + 1, i);
            // dp[i][c][1] = dp[i][c][0] + cal(i, c, i, c); // 关完 [i,c] 后再从 i 走回 c
        }

        // 只往右扩
        for (int j = c + 1; j <= n; ++j) {
            dp[c][j][1] = dp[c][j - 1][1] + cal(c, j - 1, j - 1, j);
            // dp[c][j][0] = dp[c][j][1] + cal(c, j, j, c); // 关完 [c,j] 后再从 j 走回 c
        }

        for (int i = c - 1; i >= 1 ; i --) {
            for (int j = c + 1; j <= n; j ++) {
                dp[i][j][0] = min (dp[i + 1][j][0] + cal (i + 1, j, i + 1, i), dp[i + 1][j][1] + cal (i + 1, j, j, i));
                dp[i][j][1] = min (dp[i][j - 1][0] + cal (i, j - 1, i, j), dp[i][j - 1][1] + cal (i, j - 1, j - 1, j));
            }
        }

        cout << min (dp[1][n][0], dp[1][n][1]) << '\n';
    } 

    signed main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        ovo();
        return 0;
    }