#include <bits/stdc++.h>
#define int long long
using namespace std;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);

    int mx = -1;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mx = max (a[i], mx);        
    }

    int ok = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == mx) {
            if (i != 1 && a[i - 1] != 0) ok = 1;
            if (i != n && a[i + 1] != 0) ok = 1;
        }
    }

    if (ok) {
        cout << mx << '\n';
    } else if (mx != 1) {
        cout << mx - 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}