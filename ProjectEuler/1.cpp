
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int ans = 0;
    for (int i = 0; i < 1000; i += 3) {
        ans += i;
    }

    for (int j = 0; j < 1000; j += 5) {
        ans += j;
    }

    for (int z = 0; z < 1000; z += 15) {
        ans -=z;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}