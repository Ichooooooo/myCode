
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m, k;
    cin >> n >> m >> k;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort (a.begin() + 1, a.end());
    multiset <int> st;
    for (int i = 1; i <= m; i ++) {
        int x; cin >> x;
        st.insert (x);
    }

    // sort (b.begin() + 1, b.end());

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        auto pos = st.lower_bound (max (0LL, a[i] - k));
        if (pos == st.end()) continue;

        if (*pos > a[i] + k) continue;

        ans++;
        st.erase (pos);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}