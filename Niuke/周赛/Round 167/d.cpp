
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort (a.begin() + 1, a.end());
    int R = 0, L = 0, mid = a[(n + 1) / 2];
    R = n - (prev(upper_bound(a.begin() + 1, a.end(), mid)) - a.begin());
    L = lower_bound(a.begin() + 1, a.end(), mid) - a.begin() - 1;

    if (L == 0 && R == 0) {
        cout << -1 << '\n';
        return;
    }

    cout << n - max (2 * L, 2 * R - 1) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}