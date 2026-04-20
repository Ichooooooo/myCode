#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int k, x, a;
    cin >> k >> x >> a;

    int c = 0;
    for (int i = 1; i <= x + 1; i ++) {
        int y = c / (k - 1) + 1;
        if (c + y > a) {
            cout << "NO" << '\n';
            return;
        } 

        c += y;
    }

    cout << "YES" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}