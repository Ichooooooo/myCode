
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;

void ovo() {
    string s; cin >> s;
    int ans = 0;

    int n = s.size(), cnt = 1;
    for (int i = 1; i < n; i ++) {
        if (s[i] == s[i - 1]) {
            ans = (ans + ((1 + cnt) * cnt / 2) % mod) % mod;
            cnt = 1;
        } else {
            cnt ++;
        }
    } 

    ans = (ans + ((1 + cnt) * cnt / 2) % mod) % mod;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}