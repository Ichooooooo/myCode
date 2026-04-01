
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int ans = -1;
    for (int i = 100; i <= 999; i ++) {
        for (int j = 100; j <= 999; j ++) {
            int t = i * j;
            string s = to_string (t);
            int ok = 1;

            for (int k = 0; k < s.size(); k ++) {
                if (s[k] != s[s.size() - 1 - k]) {
                    ok = 0;
                }
            }

            if (ok) {
                ans = max (ans, t);
            }
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