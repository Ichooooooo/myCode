
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int h, n;
    cin >> h >> n;
    vector <int> a (n);
    for (int & i : a) cin >> i;

    int now = h;
    for (int i = 0; i < n; i ++) {
        int d1 = 2 + max (0LL, a[i] - 20);
        int d2 = max (0LL, (a[i] + 1) / 2 - 5);
        int d3 = max (0LL, a[i] - 16);

        int d = min ({d1, d2, d3});
        now -= d;
        if (now <= 0) {
            cout << "NO" << '\n';
            cout << i << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
    cout << now << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}