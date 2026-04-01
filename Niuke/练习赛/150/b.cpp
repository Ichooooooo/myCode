
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;

    vector <array<int, 2> > a (n);

    int ok = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
        if (a[i][1] - a[i][0] + 1 > 100) ok = 1;
    }


    if (ok) {
        cout << 1 << '\n';
    } else {
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            auto [l, r] = a[i];
            for (int j = l; j <= r; j ++) {
                ans = gcd (ans, j);
            }
        }

        cout << ans << '\n';
    }

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}