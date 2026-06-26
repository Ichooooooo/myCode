
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, q; cin >> n >> q;

    vector <int> a (n + 1), pre (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    while (q --) {
        int l, r;
        cin >> l >> r;

        cout << pre[r] - pre[l - 1] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}