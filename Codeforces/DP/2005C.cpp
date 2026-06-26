
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

char cc[5] = {'n', 'a', 'r', 'e', 'k'};

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <string> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    const int INF = 1e15;
    vector <int> dp (5, -INF);
    dp[0] = 0;
    
    for (int i = 0; i < n; i ++) {
        vector <int> ndp = dp;
        vector <int> vis = {0, 1, 2, 3, 4};

        for (int j = 0; j < m; j ++) {
            for (int k = 0; k < 5; k ++) {
                if (a[i][j] == cc[vis[k]]) {
                    ndp[k]++;
                    vis[k] = (vis[k] + 1) % 5;
                } else {
                    if (a[i][j] == 'n' || a[i][j] == 'a' || a[i][j] == 'r' || a[i][j] == 'e' || a[i][j] == 'k')
                    ndp[k]--;
                }
            }
        }

        for (int j = 0; j < 5; j ++) {
            dp[vis[j]] = max (dp[vis[j]], ndp[j]);
        }
    }

    int mx = 0;
    for (int i = 0; i < 5; i ++) {
        mx = max (mx, dp[i] - 2 * i);
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}