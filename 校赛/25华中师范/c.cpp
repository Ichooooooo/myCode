
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    for (int i = 0; i <= 64; i ++) {
        int x = (1LL << i);
        if (x > r) break;
        if (x >= l && x <= r) ans ++;
    }

    cout << r - l + 1 - ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}