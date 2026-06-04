// 1. 弄混l, r当他们的顺序不一样时候
// 2. 贪心理解错误
// 3. lower和upper用前三思

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, k;
    cin >> n >> k;

    vector <arr2> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        int l, r;
        cin >> l >> r;
        a[i][0] = r, a[i][1] = l;
    }

    if (n == k) {
        cout << n << '\n';
        return;
    }

    sort (a.begin() + 1, a.end());
    
    multiset <int> st;
    for (int i = 1; i <= k; i ++) {
        st.insert(0);
    }

    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        int l = a[i][1], r = a[i][0];
        
        auto pos = st.upper_bound (l);

        if (pos == st.begin()) continue;

        pos = prev(pos);

        // cerr << l << ' ' << r << ' ' << *pos << '\n';
        st.erase (pos);
        st.insert (r);
        cnt++;
    }

    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}