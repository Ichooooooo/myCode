
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > a (n + 1, vector <int> (m + 1));

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    int x = a[1][1];
    const int N = 400;
    vector <int> tmp; tmp.reserve (N);
    
    tmp.push_back (x);

    for (int i = 2; i * i <= x; i ++) {
        if (x % i == 0) {
            tmp.push_back (i);
            if (i * i != x) {
                tmp.push_back (x / i);
            }
        }
    }

    sort (tmp.rbegin(), tmp.rend());
    
    vector <vector <int> > dp (n + 1, vector <int> (m + 1));

    for (int i = 0; i < tmp.size(); i ++) {
        for (int j = 1; j <= n; j ++) {
            for (int z = 1; z <= m; z ++) {
                dp[j][z] = 0;
            }
        }

        int x = tmp[i];
        dp[1][1] = 1;

        for (int j = 1; j <= n; j ++) {
            for (int k = 1; k <= m; k ++) {
                if (j - 1 >= 1) {
                    dp[j][k] |= (dp[j - 1][k] & (a[j][k] % x == 0));
                } 
                if (k - 1 >= 1) {
                    dp[j][k] |= (dp[j][k - 1] & (a[j][k] % x == 0));
                }
            }
        }

        if (dp[n][m]) {
            cout << x << '\n';
            return;
        }
    }

    cout << 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}