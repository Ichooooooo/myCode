
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;

    if (n == 0) {
        cout << "Yes" << '\n';
        return;
    }

    vector <int> a;
    int t = n;
    while (t) {
        a.push_back (t & 1);
        // cerr << a.back ();
        t >>= 1;
    }

    vector <int> b;
    int l = -1, r = -1;
    for (int i = 0; i < a.size(); i ++) {
        if (a[i] == 1) {
            l = i; break;
        }
    }

    for (int i = a.size() - 1; i >= 0; i --) {
        if (a[i] == 1) {
            r = i;
            break;
        }
    }
    // cerr << '\n';
    // cerr << l << ' ' << r << '\n';

    int len = r - l + 1;
    if ((len & 1) && (a[(l + r) / 2] == 1)) {
        cout << "No" << '\n';
        return;
    }

    for (int i = l; i <= r; i ++) {
        if (a[i] != a[r + l - i]) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}