
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int x = 600851475143;
    int mx = 1;

    int cnt = 0;
    while (x % 2 == 0) {
        x /= 2;
        cnt++;
    }

    if (cnt) {
        mx = max (mx, 2LL);
    }

    for (int i = 3; i * i <= x; i += 2) {
        int cnt = 0;
        while (x % i == 0) {
            cnt++;
            x /= i;
        }
        if (cnt) {
            mx = max (mx, i);
        }
    }

    if (x > 1) mx = max (mx, x);

    cout << mx << '\n';


    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}