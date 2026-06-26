
#include <bits/stdc++.h>
// #define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

const int N = 41;
int dp[N][N][N][N];

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <int> cn(4);
    for (int i = 0; i < m; i ++) {
        int x; cin >> x;
        cn[x - 1]++;
    }

    dp[0][0][0][0] = a[1];
    for (int i = 0; i <= cn[0]; i ++) {
        for (int j = 0; j <= cn[1]; j ++) {
            for (int k = 0; k <= cn[2]; k ++) {
                for (int z = 0; z <= cn[3]; z ++) {
                    int s = i + 2 * j + 3 * k + 4 * z + 1;
                    
                    if (i > 0) dp[i][j][k][z] = max (dp[i][j][k][z], dp[i - 1][j][k][z] + a[s]);
                    if (j > 0) dp[i][j][k][z] = max (dp[i][j][k][z], dp[i][j - 1][k][z] + a[s]);
                    if (k > 0) dp[i][j][k][z] = max (dp[i][j][k][z], dp[i][j][k - 1][z] + a[s]);
                    if (z > 0) dp[i][j][k][z] = max (dp[i][j][k][z], dp[i][j][k][z - 1] + a[s]);

                    // cerr << "s : " << s << ' ' << dp[i][j][k][z] << '\n';
                }
            }
        }
    }

    cout << dp[cn[0]][cn[1]][cn[2]][cn[3]] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}