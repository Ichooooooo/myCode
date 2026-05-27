#include <bits/stdc++.h>
#define int long long
using namespace std;

void ovo() {
    int x, y;
    cin >> x >> y;
    int n = x + y;

    if (x > n / 2 || y > (n - 1 + (n & 1))) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    
    if (n & 1) {
        int now = 2;
        for (int i = 1; i <= x; i ++) {
            cout << 1 << ' ' << now << '\n';
            cout << now << ' ' << now + 1 << '\n';
            now += 2;
        }

        for (int i = now; i <= n; i ++) {
            cout << 1 << ' ' << i << '\n';
        }
    } else {
        int now = 2;
        for (int i = 1; i <= x - 1; i++) {
            cout << 1 << ' ' << now << '\n';
            cout << now << ' ' << now  + 1 << '\n';
            now += 2;
        }

        for (int i = now; i <= n; i ++) {
            cout << 1 << ' ' << i << '\n';
        }
    }

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}