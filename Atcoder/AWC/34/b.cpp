
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n);
    for (int i = 1; i <= n - 1; i ++) {
        cin >> a[i];
    }

    int ans = 1, now = 1;
    while(now != n) {
        now = a[now];
        ans++;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}