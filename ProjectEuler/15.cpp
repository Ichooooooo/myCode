#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using i128 = __int128;

void ovo() {
    i128 ans = 1;
    for (int i = 21; i <= 40; i ++) {
        ans = ans * i;
    }

    for (int i = 1; i <= 20; i ++) {
        ans /= i;
    }

    cout << (int) ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}