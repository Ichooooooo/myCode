
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, p;
    cin >> n >> p;

    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        a[i] %= p;
    }

    sort (a.begin(), a.end());

    int mx = 0;
    for (int i = 0; i < n - 1; i ++) {
        auto pos = lower_bound(a.begin() + i + 1, a.end(), p - a[i]);
        mx = max ({mx, (a[i] + a[n - 1]) % p, (a[i] + a[pos - a.begin() - 1]) % p});
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}