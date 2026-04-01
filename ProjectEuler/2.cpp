
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
using i128 = __int128;
const int MX = 4e6;

void ovo() {
    int ans = 2;
    vector <int> a (MX);
    a[0] = 1; a[1] = 2;
    for (int i = 2; i < MX; i ++) {
        a[i] = a[i - 1] + a[i - 2];
        if (a[i] > MX) break;
        if (a[i] % 2 == 0) {
            ans += a[i];
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