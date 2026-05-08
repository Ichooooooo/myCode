
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 2005;
int g[N][N];

void ovo() {
    int n, m;
    cin >> n >> m;
    vector <int> a (n + 1);
    
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <int> dp (m + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = m; j >= a[i]; j --) {
            dp[j] = (dp[j - a[i]] + dp[j]) % 10;
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j <= m; j ++) {
            if (j < a[i]) {
                g[i][j] = dp[j];
            } else {
                g[i][j] = (dp[j] - g[i][j - a[i]] + 10) % 10;
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << g[i][j];
        }

        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}