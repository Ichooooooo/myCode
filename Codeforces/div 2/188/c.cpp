
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;

    int mx = lcm (a, lcm (b, c));
    int a1 = 0, a2 = 0, a3 = 0;
    
    int ad = m / mx;
    int g12 = lcm (a, b), g13 = lcm (a, c), g23 = lcm (b, c);

    int d12 = m / g12 - ad, d13 = m / g13 - ad, d23 = m / g23 - ad;
 
    // cerr << ad << ' ' << d12 << ' ' << d13 << ' ' << d23 << '\n';
    a1 = ad * 2 + d12 * 3 + d13 * 3 + (m / a - ad - d12 - d13) * 6;
    a2 = ad * 2 + d12 * 3 + d23 * 3 + (m / b - ad - d12 - d23) * 6; 
    a3 = ad * 2 + d13 * 3 + d23 * 3 + (m / c - ad - d13 - d23) * 6;
    cout << a1 << ' ' << a2 << ' ' << a3 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}