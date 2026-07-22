
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> p (n);

    for (int i = 0; i < n; i ++) {
        cin >> p[i];
    }

    sort (p.rbegin(), p.rend());

    int ans = 0;
    for (int i = 0; i < n / 2; i ++) {
        ans = ans + (p[i] - p[n - 1 - i]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}