
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, s, t;
    cin >> n >> s >> t;
    
    int ans = 0, x;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        if (abs (x - s) <= t) ans ++;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}