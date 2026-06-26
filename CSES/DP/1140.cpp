// 更自然的写法 : dp[i] = max(dp[i - 1], dp[j] + p[i])

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <arr3> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        int l, r, p;
        cin >> l >> r >> p;
        a[i][0] = r, a[i][1] = l, a[i][2] = p;
    }

    sort (a.begin() + 1, a.end());

    vector <int> pre (n + 1), last (n + 1), dp (n + 1);

    const int INF = 1e10;
    for (int i = 1; i <= n; i ++) {
        auto [r, l, p] = a[i];
        auto pos = upper_bound (a.begin() + 1, a.end(), arr3{l - 1, INF, INF});

        last[i] = prev(pos) - a.begin();
        // cerr << "i : " << i << ' ' << last[i] << '\n';
    } 

    for (int i = 1; i <= n; i ++) {
        dp[i] = pre[last[i]] + a[i][2];

        pre[i] = max (pre[i - 1], dp[i]);
    }

    cout << pre[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}