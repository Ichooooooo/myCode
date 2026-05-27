
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct BIT {
    vector <int> bit;
    int n;

    BIT (int x = 0) : n(x) {
        bit.assign (n + 1, 0);
    }

    static int lowbit (int x) {
        return (x & -x);
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit(i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            ans += bit[i];
        }

        return ans;
    }
};

void ovo() {
    int n, m;
    cin >> n >> m;

    BIT bit (n);
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        bit.point_add (i, x);
    }

    int opt, x, y;
    while (m --) {
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            bit.point_add (x, y);
        } else {
            cin >> x >> y;
            cout << bit.sum (y) - bit.sum (x - 1) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}