    
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a (n + 1), pre (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i] += m;
        pre[i] = pre[i - 1] + a[i];
    }

    // int ans = 0;
    // set <int> st;
    // for (int i = 1; i <= n; i ++) {
    //     st.insert(pre[i]);
    //     int ll = pre[i] - k;
    //     auto pos = st.lower_bound (ll) -s ;
    //     // cerr << ll << ' ' << pos << ' ' << i - pos <<  '\n';
    //     ans += (i - pos);
    // }   

//     cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}