
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n;  cin >> n;
    vector <int> a (n + 1);
    
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int ans = 0;

    int l = 1, r = 1;
    map <int, int> mp;
    while (r <= n) {
        while (l <= r && l <= mp[a[r]]) {
            mp[a[l]] = 0;
            l ++;
        }

        // cerr << "rl : " << l << ' ' << r << '\n';
        mp[a[r]] = r;
        int len = r - l + 1;
        ans = ans + len;
        r++;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}