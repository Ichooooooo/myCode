#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> vis (10);

    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        vis[x]++;
    }

    int nm = n / 9;
    int res = n % 9;
    int cn0 = 0, cn1 = 0;
    for (int i = 1; i <= 9; i ++) {
        if (vis[i] == nm) {
            cn0++;
        } else if (vis[i] == nm + 1) {
            cn1++;
        }
    }

    if ((res == 0 && cn0 == 9) || (res != 0 && cn0 == 9 - res && cn1 == res)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}