
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;
    
    multiset <int> st;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        st.insert (x);
    }

    vector <int> ans (m);
    for (int i = 0; i < m; i ++) {
        int x; cin >> x;
        auto pos = st.upper_bound (x);
        if (pos == st.begin()) {
            ans[i] = -1;
        } else {
            ans[i] = *prev(pos);
            st.erase(prev(pos));
        }
    }

    for (int i = 0; i < m; i ++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}