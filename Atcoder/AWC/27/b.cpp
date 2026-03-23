
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n);
    for (int & i : a) cin >> i;

    int x, pos = -1;
    for (int i = 0; i < n; i ++) {
        if (i == 0) x = a[0];
        if (a[i] > x) {
            x = a[i];
            pos = i + 1;
        }
    }

    cout << pos << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}