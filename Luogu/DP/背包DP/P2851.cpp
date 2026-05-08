
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e12;

void ovo() {
    int n, t; cin >> n >> t;
    vector <int> v (n), c (n);
    
    int mx = 0, sum = 0;
    for (int i = 0; i < n; i ++) {
        cin >> v[i];
        mx = max (mx, v[i]);
    }

    for (int i = 0; i < n; i ++) {
        cin >> c[i];
        sum += v[i] * c[i];
    }

    if (sum < t) {
        cout << -1 << '\n';
    }

    vector <int> dp (t + mx + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i ++) {
        int k = c[i];
        // cerr << "i : " << i << ' ' << k << '\n';
        for (int j = 0; k > 0; j ++) {
            int now = min(k, (1LL << j));
            k -= now;
            // cerr << "now : " << now << '\n'; 
            int cs = now * v[i];
            // cerr << "now : " << now << ' ' << cs << '\n';
            for (int p = t + mx; p >= cs; p --) {
                dp[p] = min(dp[p], dp[p - cs] + now);
                // cerr << "p : " << p << ' ' << dp[p] << '\n';
            }
        }
    }

    vector <int> ndp (t, INF);
    ndp[0] = 0;
    
    // cerr << "mx : " << mx << '\n';
    for (int i = 0; i < n; i ++) {
        for (int j = v[i]; j < t; j ++) {
            ndp[j] = min(ndp[j], ndp[j - v[i]] + 1);
        }
    }

    int mn = INF;
    for (int i = t; i <= t + mx; i ++) {
        // cerr << "i : " << i << ' ' << dp[i] << ' ' << ndp[i - t] << '\n';
        int tmp = dp[i] + ndp[i - t];
        mn = min (mn, tmp);
    }

    if (mn >= 1e7) {
        cout << -1 << '\n';
    } else {
        cout << mn << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}