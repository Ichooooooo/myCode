
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);

    map <int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mp[a[i] - i] ++;
    }

    int mx = -1;
    for (auto [x, y] : mp) {
        mx = max (mx, y);
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    cin >> _;

    while (_--) ovo();
}