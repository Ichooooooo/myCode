
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n, W;
    cin >> n >> W;

    vector <int> dp (W + 5);
    for (int i = 1; i <= n; i ++) {
        int v, w, m;
        cin >> v >> w >> m;

        for (int k = 1; m > 0; k <<= 1) {
            int nm = min (k, m);
            m -= nm;
            for (int j = W; j >= w * k; j --) {
                dp[j] = max (dp[j], dp[j - w * nm] + nm * v);
            }
        }
    }

    cout << dp[W] << '\n';
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}