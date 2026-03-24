
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, q; cin >> n >> q;
    vector <int> a (n + 1);
    vector <int> pre (n + 1);
    pre[0] = 0;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = max (pre[i - 1], a[i]);
    }

    while (q--) {
        int x; cin >> x;
        cout << pre[x] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}