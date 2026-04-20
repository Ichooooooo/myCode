#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    int t = (n + 1) / 2 - 1;
    int ans = 0;
    for (int i = t; i >= 0; i --) {
        if (s[i] == s[t]) {
            ans++;
        } else {
            break;
        }
    }

    for (int i = t + 1; i <= n; i ++) {
        if (s[i] == s[t]) {
            ans++;
        } else {
            break;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}