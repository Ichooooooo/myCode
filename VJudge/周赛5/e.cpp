
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    map <arr2, int> mp;
    int ans = 0;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '0') c1++;
        else if (s[i] == '1') c2++;
        else c3++;

        if (c1 == c2 && c2 == c3) ans++;
        
        int ch1 = c2 - c1;
        int ch2 = c3 - c2;

        if (mp.find({ch1, ch2}) != mp.end()) {
            ans += mp[{ch1, ch2}];
        }

        mp[{ch1, ch2}]++;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}