
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m;
    cin >> n >> m;

    if (m > n) {
        cout << -1 << '\n';
        return;
    }

    if (n == m) {
        cout << m << ' ' << 0 << '\n';
        return;
    }

    int a = m, b = 0, ch = n - m, now = 0;

    for (int i = 62; i >= 0; i --) {

        cerr << i << '\n';
        cerr << ch << '\n';
        if ((ch >> i) & 1LL) now += (1LL << i);
    
        if ((m >> i) & 1LL) continue;

        cerr << i << '\n';
        cerr << now << '\n';

        if (now >= 2 * (1LL << i)) {
            a += (1LL << i);
            b += (1LL << i);
            now -= 2 * (1LL << i);
        }
    }

    if (now != 0) {
        cout << -1 << '\n';
        return;
    }

    cout << a << ' ' << b << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}