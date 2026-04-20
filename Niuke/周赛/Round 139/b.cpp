#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;
    
    if (n == 1 && m == 1) {
        cout << -1 << '\n';
        return;
    }
    if (m == 1) {
        cout << 0 << '\n' << 1 << '\n';
        for (int i = 3; i <= n; i ++) {
            cout << 1 << '\n';
        }
    } else if (n == 1) {
        cout << "01";
        for (int i = 3; i <= m; i ++) {
            cout << 1;
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}