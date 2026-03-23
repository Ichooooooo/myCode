
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> idx (n + 1);
    for (int i = 0; i < n - 1; i ++) {
        int u, v; cin >> u >> v;
        idx[u] ++;
        idx[v] ++;
    }

    int x; cin >> x;

    if (idx[x] == 1) {
        cout << "xiaonian wins!" << '\n';
    } else if ((n - 1) & 1) {
        cout << "xiaonian wins!" << '\n';
    } else {
        cout << "coldtree wins!" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}