
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    set <int> stl;
    int ans = -1e8;
    for (int i = 1; i<= n; i++) {
        int now = a[i] - i;
        stl.insert (now);
        int mn = *stl.begin();
        ans = max (ans, now - mn);
    }

    set <int> str;
    for (int i = n; i >= 1; i--) {
        int now = a[i] + i;
        str.insert (now);
        int mn = *str.begin();
        ans = max (ans, now - mn);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}