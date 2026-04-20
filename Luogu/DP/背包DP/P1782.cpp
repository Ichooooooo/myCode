
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m, C;
    cin >> n >> m >> C;

    vector <int> dp (C + 5);
    
    for (int i = 1; i <= n; i ++) {
        int v, w, d;
        cin >> v >> w >> d;

        for (int k = 1; d > 0; k <<= 1) {
            int nm = min (d, k);
            d -= nm;

            for (int j = C; j >= nm * v; j --) {
                dp[j] = max (dp[j], dp[j - nm * v] + nm * w);
            }
        }
    }

    for (int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        for (int j = C; j >= 1; j --) {
            
            for (int k = 0; k <= j; k ++) {
                int cs = a * k * k + b * k + c;
                dp[j] = max (dp[j], dp[j - k] + cs);
            }
        }
    }

    
    cout << dp[C] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}