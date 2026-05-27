
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e17;
const int N = 210;
int dp[N][N][N];

void ovo() {
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            for (int z = 0; z < m; z ++) {
                dp[i][j][z] = INF;
            }
        }
    }

    vector <vector <int> > a (n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    // hang
    vector <vector <int> > rmn (n + 1, vector <int> (m + 1, INF));
    for (int i = 0; i < m; i ++) {
        int p = (1 - 1 + i) % m + 1;
        dp[1][1][i] = a[1][p] + k * i;
        rmn[1][1] = min (dp[1][1][i], rmn[1][1]);
        for (int j = 2; j <= m; j ++) {
            int p = (j - 1 + i) % m + 1;
            dp[1][j][i] = dp[1][j - 1][i] + a[1][p];
            rmn[1][j] = min (rmn[1][j], dp[1][j][i]);
        }
    }

    // lie
    for (int i = 2; i <= n; i ++) {
        for (int j = 0; j < m; j ++) {
            int p = (1 - 1 + j) % m + 1;
            dp[i][1][j] = rmn[i - 1][1] + k * j + a[i][p];
            rmn[i][1] = min (rmn[i][1], dp[i][1][j]);
        }
    }

    for (int i = 2; i <= n; i ++) {
        for (int j = 2; j <= m; j ++) {
            for (int z = 0; z < m; z ++) {
                int p = (j - 1 + z) % m + 1;
                dp[i][j][z] = min (dp[i][j - 1][z] + a[i][p], rmn[i - 1][j] + k * z + a[i][p]);
                rmn[i][j] = min (rmn[i][j], dp[i][j][z]);
            }
        }
    }

    cout << rmn[n][m] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}