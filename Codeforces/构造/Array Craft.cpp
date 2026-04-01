
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, x, y;
    cin >> n >> x >> y;

    int now = 1;
    if ((y - 1) & 1) now *= -1;
    for (int i = 1; i < y; i ++) {
        cout << now << ' ';
        now *= -1;
    }

    for (int i = y; i <= x; i ++) {
        cout << 1 << ' ';
    }

    now = -1;
    for (int i = x + 1; i <= n; i ++) {
        cout << now << ' ';
        now *= -1; 
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}