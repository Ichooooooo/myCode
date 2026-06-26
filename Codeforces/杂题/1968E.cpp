
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    
    if (n == 2) {
        cout << 1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    } else if (n == 3) {
        cout << 2 << ' ' << 1 << '\n';
        cout << 2 << ' ' << 3 << '\n';
        cout << 3 << ' ' << 1 << '\n';
    } else {
        cout << 1 << ' ' << 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';

        for (int i = 3; i <= n; i ++) {
            cout << i << ' ' << i << '\n';
        }
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}