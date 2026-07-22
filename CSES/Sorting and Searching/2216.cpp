
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    set <int> st;
    for (int i = 0; i < n; i ++) {
        auto pos = st.find (a[i] - 1);
        if (pos != st.end()) {
            st.erase (pos);
        }
        st.insert (a[i]);
    }

    cout << st.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}