
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

const int INF = 1e18;

void ovo() {
    int n, m; cin >> n >> m;
    vector <int> k (n + 1), c (n + 1);

    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> k[i];
    }

    for (int j = 1; j <= n; j ++) {
        cin >> c[j];
        sum += k[j] * c[j];
    }

    vector <int> dp (sum + 5, 1);

    for (int i = 1; i <= n; i ++) {
        
        for (int j = sum; j >= 0; j --) {

            for (int p = 1; p <= k[i]; p ++) {
                if (j >= p * c[i]) dp[j] = max (dp[j], min(INF, dp[j - p * c[i]] * p));
            }
        }
    }


    int mn = -1;
    for (int i = 1; i <= sum; i ++) {
        if (dp[i] >= m) {
            if (mn == -1) mn = i;
            else mn = min (mn, i);
        }
    }

    cout << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}