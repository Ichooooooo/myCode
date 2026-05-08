
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;


void ovo() {
    int h, w; cin >> h >> w;
    vector <string> a (h);

    for (int i = 0; i < h; i ++) {
        cin >> a[i];
    }

    vector <vector <int> > dp (h, vector <int> (w));

    dp[0][0] = 1;

    
    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            if (a[i][j] == '#') continue;

            if (i - 1 >= 0) dp[i][j] = dp[i - 1][j];
            if (j - 1 >= 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            // cerr << "pt : " << i << ' ' << j << ' ' << dp[i][j] << '\n';
        } 
    }

    cout << dp[h - 1][w - 1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}