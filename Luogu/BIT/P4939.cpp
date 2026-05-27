
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct BIT {
    int n;
    vector <int> bit;

    BIT (int x) : n (x) {
        bit.assign (n + 5, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit(i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit (i)) {
            ans += bit[i];
        }
        return ans;
    }
};

void ovo() {
    int n, m;
    cin >> n >> m;

    BIT bit (n);
    int opt;
    while (m -- ) {
        cin >> opt;
        if (opt == 0) {
            int a, b;
            cin >> a >> b;
            bit.point_add(a, 1);
            bit.point_add(b + 1, -1);
        } else {
            int x; cin >> x;
            cout << bit.sum (x) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}