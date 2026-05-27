
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n), b (n);
    for (int & i : a) cin >> i;
    for (int & i : b) cin >> i;

    int mn = 0, mx = 0, ans;
    for (int i = 0; i < n; i ++) {
        if (i == n - 1) {
            ans = max (b[i] - mn, mx - a[i]);
        } else {
            int tmn, tmx;
            tmn = min (mn - a[i], b[i] - mx);
            tmx = max (mx -  a[i], b[i] - mn);
            mn = tmn;
            mx = tmx;
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