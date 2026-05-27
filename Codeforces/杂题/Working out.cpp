
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 1005;
int a[N][N];
int dpa1[N][N], dpa2[N][N], dpb1[N][N], dpb2[N][N];

void ovo() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    dpa1[1][1] = a[1][1];
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (i - 1 >= 1)
            dpa1[i][j] = max (dpa1[i][j], dpa1[i - 1][j] + a[i][j]);
            if (j - 1 >= 1) 
            dpa1[i][j] = max (dpa1[i][j], dpa1[i][j - 1] + a[i][j]);
        }
    }

    dpa2[n][m] = a[n][m];
    for (int i = n; i >= 1; i --) {
        for (int j = m; j >= 1; j --) {
            if (i + 1 <= n) dpa2[i][j] = max (dpa2[i][j], dpa2[i + 1][j] + a[i][j]);
            if (j + 1 <= m) dpa2[i][j] = max (dpa2[i][j], dpa2[i][j + 1] + a[i][j]);
        }
    }    

    dpb1[n][1] = a[n][1];
    for (int i = n; i >= 1; i --) {
        for (int j = 1; j <= m; j ++) {
            if (j - 1 >= 1)
            dpb1[i][j] = max (dpb1[i][j], dpb1[i][j - 1] + a[i][j]);
            if (i + 1 <= n) 
            dpb1[i][j] = max (dpb1[i][j], dpb1[i + 1][j] + a[i][j]);
        }
    }    

    dpb2[1][m] = a[1][m];
    for (int i = 1; i <= n; i ++) {
        for (int j = m; j >= 1; j --) {
            if (i - 1 >= 0) dpb2[i][j] = max (dpb2[i][j], dpb2[i - 1][j] + a[i][j]);
            if (j + 1 <= m) dpb2[i][j] = max (dpb2[i][j], dpb2[i][j + 1] + a[i][j]);
        }
    }    

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (i - 1 >= 1 && i + 1 <= n && j - 1 >= 1 && j + 1 <= m) {
                // cerr << "i : " << i << ' ' << j << ' ' << '\n';
                ans = max (ans, dpa1[i][j - 1] + dpa2[i][j + 1] + dpb1[i + 1][j] + dpb2[i - 1][j]);
                ans = max (ans, dpb1[i][j - 1] + dpb2[i][j + 1] + dpa1[i - 1][j] + dpa2[i + 1][j]);

                // cerr << "dp : " << ans << '\n';
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}