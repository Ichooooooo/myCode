
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int a1 = 0, a2 = 0;
    for (int i = 1; i <= 100; i ++) {
        a2 += i * i;
    }

    a1 = (1 + 100) * 100 / 2;

    cout << a1 * a1  - a2;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}