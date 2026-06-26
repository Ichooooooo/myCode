
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    set <int> st;
    
    for (int i = 1; i <= n; i ++) {
        auto pos = st.lower_bound(a[i]);
        
        if (pos == st.end()) {
            st.insert(a[i]);
        } else {
            st.erase (pos);
            st.insert (a[i]);
        }
    }

    cout << st.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}