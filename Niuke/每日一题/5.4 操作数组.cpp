
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> a (n), b (n);

    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        s1 += a[i];
    }

    for (int i = 0; i < n; i ++) {
        cin >> b[i];
        s2 += b[i];
    }

    if (s1 != s2) {
        cout << -1 << '\n';
        return;
    }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += abs (a[i] - b[i]);
    }

    cout << ans / 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}