
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m;
    cin >> n >> m;
    vector <int> c (n + 1), d (n + 1);
    for (int i = 1; i <= n; i ++) cin >> c[i];

    int ans = 0;
    while (m --) {
        int x; cin >> x;
        if (d[x] + 1 <= c[x]) {
            d[x]++;
            ans++;
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