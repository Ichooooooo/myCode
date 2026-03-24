
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9;
using i128 = __int128_t;

void ovo() {
    int n, m;
    cin >> n >> m;

    int ans = 1;
    if (m - n + 1 <= 100) {
        for (int i = n; i <= m; i ++) {
            ans = ans * i % mod;
        }
    } else {
        ans = 0;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}