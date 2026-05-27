#include <bits/stdc++.h>
#define int long long
using namespace std;

void ovo() {
    int sum = 0, mx = -100;
    for (int i = 0; i < 7; i ++) {
        int x; cin >> x;
        sum += x;
        mx = max (mx, x);
    }

    cout << (sum - mx) * (-1) + mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}