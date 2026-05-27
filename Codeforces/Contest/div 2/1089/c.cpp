
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1), b (n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (i == 1) {
            if (gcd(a[i], a[i + 1]) != a[i]) {
                ans++;
            }

            // cerr << 1 << '\n';
        } else if (i == n) {
            if (gcd(a[i], a[i - 1]) != a[i]) {
                ans++;
            } 

            // cerr << 2 << '\n';
        } else {
            int x = a[i - 1], y = a[i + 1], z = a[i];
            
            if (gcd(x, z) / gcd (gcd(x, y), z) * (gcd (y, z) ) != a[i]) {
                ans++;
            }

            // cerr << 3 << '\n';
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