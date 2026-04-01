
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <array<int, 2>> a (n);
    for (auto & [y, x] : a) cin >> x >> y;

    sort (a.begin(), a.end());
    int ans = 1, now = a[0][0];
    for (int i = 1; i < n; i ++) {
        if (a[i][1] >= now) {
            ans++;
            now = a[i][0];
            // cerr << now << ' ' << a[i][0] << ' ' << a[i][1] << '\n';
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}