#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n, x;
    cin >> n >> x;
    vector <int> h (n), s (n);
    for (int i = 0; i < n; i ++) {
        cin >> h[i];
    }

    for (int i = 0; i < n; i ++) {
        cin >> s[i];
    }

    vector <int> dp (x + 1);
    
    for (int i = 0; i < n; i ++) {
        for (int j = x; j >= h[i]; j --) {
            dp[j] = max (dp[j], dp[j - h[i]] + s[i]);
        }
    }

    cout << dp[x] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}