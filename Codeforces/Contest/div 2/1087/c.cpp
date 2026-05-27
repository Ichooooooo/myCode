
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;

    for (int i = 1; i <= 2 * n - 3; i += 2) {
        cout << "? " << i << ' ' << i + 1 << endl;
        int x; cin >> x;
        if (x == 1) {
            cout << "! " << i << endl;
            return;
        }
    }

    cout << "? " << 2 * n << ' ' << 1 << endl;
    int y; cin >> y;
    if (y == 1) {
        cout << "! " << 2 * n << endl;
        return;
    } 

    cout << "? " << 2 * n << ' ' << 2 << endl;
    int z; cin >> z;
    if (z == 1) {
        cout << "! " << 2 * n << endl;
        return;
    } 

    cout << "! " << 2 * n - 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}