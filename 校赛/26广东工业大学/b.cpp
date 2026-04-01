
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <array<int, 3>> a (n + 1);

    for (int i = 1; i<= n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }

    sort (a.begin(), a.end());

    cout << 3 << ' ' << 3 << '\n';

    cout << a[1][2] << ' ' << a[2][2] << ' ' << a[3][2] << '\n';
    cout << a[n][2] << ' ' << a[n - 1][2] << ' ' << a[n - 2][2] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}