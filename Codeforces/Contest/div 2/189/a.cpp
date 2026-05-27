
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int x, y;
    cin >> x >> y;

    int ch = y - x;
    if (ch < x) {
        cout << "NO" << '\n';
        return;
    }

    for (int i = 2; i * x < y; i ++) {
        if (y % (i * x) != 0) {
            cout << "YES" << '\n';
            return;
        }
    } 

    cout << "NO" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}