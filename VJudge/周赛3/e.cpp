
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector <int> b (n, -1);
    int rpos = 0;
    for (int i = 0; i < n; i ++) {
        while (rpos < n && a[i] == a[rpos]) {
            rpos++;
        }

        if (rpos < n) {
            b[i] = rpos;
        } 

        // cerr << "i : " << i << ' ' << b[i] << '\n';
    }

    // cerr << '\n';
    int q; cin >> q;
    while (q --) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (b[l] == -1 || (b[l] > r)) {
            cout << -1 << ' ' << -1 << '\n';
        } else {
            cout << l + 1 << ' ' << b[l] + 1 << '\n';
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