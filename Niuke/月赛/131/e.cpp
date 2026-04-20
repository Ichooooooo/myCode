#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n, k; cin >> n >> k;
    int x, y; cin >> x >> y;

    const int INF = 1e15;
    vector <vector <int> > dp (x + 1, vector <int> (y + 1, INF));
    
    dp[0][0] = 0;
    
    for (int z = 1; z <= n; z ++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (z <= k) {
            for (int i = x; i >= 0; i --) {
                for (int j = y; j >= 0; j --) {
                    int xi = min(x, i + a);
                    int yi = min(y, j + b);

                    dp[xi][yi] = min (dp[xi][yi], dp[i][j] + c);
                }
            }
        } else {
            for (int i = 0; i <= x; i ++) {
                for (int j = 0; j <= y; j ++) {
                    int xi = min(x, i + a);
                    int yi = min(y, j + b);

                    dp[xi][yi] = min (dp[xi][yi], dp[i][j] + c);                    
                }
            }
        }
    }

    if (dp[x][y] == INF) {
        cout << -1 << '\n';
    } else {
        cout << dp[x][y] << '\n';
    }
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}