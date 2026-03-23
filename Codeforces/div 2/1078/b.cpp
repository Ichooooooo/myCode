
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, x, y; 
    cin >> n >> x >> y;
    vector <int> a (n);
    
    for (int & i : a) cin >> i;
    int mx = 0, p = -1;
    for (int i = 0; i < n;i ++) {
        int t = a[i] % x + a[i] / x * (x - y);
        if (mx <= t) {
            mx = t;
            p = i;
        }

        // cerr << t << ' ' << mx << '\n';
    }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        if (i == p) {
            ans += a[i];
        } else {
            ans += (a[i] / x * y);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}