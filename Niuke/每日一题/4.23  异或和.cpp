
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    unordered_map <int, int> mp;

    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        mp[x]++;
    }

    int ans = 0;
    for (auto [x, y] : mp) {
        if (y & 1) {
            ans = (ans ^ x);
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