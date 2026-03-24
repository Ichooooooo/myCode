
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int qpow (int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv (int x) {
    return qpow (x, mod - 2) % mod;
}

void ovo() {
    int x, y; cin >> x >> y;
    int a, b, c; cin >> a >> b >> c;

    int fm = a + b;
    int ans = 0;

    int pwin = a * inv (fm) % mod;
    int plos = b * inv (fm) % mod;

    // cerr << pwin << ' ' << plos << '\n';

    int win = 0, los = 0;
    
    // x >= y
    auto cal1 = [&] () -> void {
        int tlos = (x - y) / y;
        int twin = 1;
        int tans = qpow (pwin, win + twin) * qpow (plos, los) % mod * (1 + mod - qpow (plos, tlos + 1)) % mod * inv ((1 + mod - plos) % mod) % mod;
 
        ans = (ans + tans) % mod;
        x -= (tlos + 1) * y;
        los += tlos + 1;

        // cerr << win << ' ' << los << ' ' << tlos << ' ' << x << '\n';
    };

    // x < y
    auto cal2 = [&] () -> void {
        int twin = (y - 1) / x;
        int tans = qpow (plos, los) * qpow (pwin, twin + win) % mod;
        // ans = (ans + tans) % mod;
        win += twin;
        y -= twin * x;

        // cerr << win << ' ' << los << ' ' << twin << ' ' << y << '\n';
    }; 

    // cerr << x << ' ' << y << '\n';

    while (x != 0 && y != 0) {
        if (x >= y) {
            // cerr << 1 << '\n';
            cal1();
            
        } else {
            // cerr << 2 << '\n';
            cal2();
            
        }
    }
    // cerr << '\n';

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}