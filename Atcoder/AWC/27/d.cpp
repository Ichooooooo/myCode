
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int m, n; cin >> m >> n;
    vector <array <int, 2>> a (m);
    for (int i = 0; i < m; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort (a.begin(), a.end(), [](auto x, auto y) {
        if (x[1] != y[1])
        return x[1] > y[1];
        else 
        return x[0] < y[0];
    });

    multiset <int> st;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        st.insert (x);
    }

    int ans = 0;
    for (int i = 0; i < m; i ++) {
        if (st.empty()) break;
        auto pos = st.lower_bound(a[i][0]);
        if (pos == st.end()) continue;
        ans += a[i][1];
        st.erase(pos);
    }

    if (!st.empty()) cout << -1 << '\n';
    else cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}