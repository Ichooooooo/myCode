
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, w;
    cin >> n >> w;
    vector <arr2> a (n);

    for (int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort (a.rbegin(), a.rend());
    int ans = 0, now = w;
    for (int i = 0; i < n; i ++) {
        auto [x, y] = a[i];
        int cnt = min (y, now);
        ans += cnt * x;
        now -= cnt;
        if (now == 0) break;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}