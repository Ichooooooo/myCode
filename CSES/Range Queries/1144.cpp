
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

struct BIT {
    int n;
    vector <int> bit;

    BIT (int n) : n (n) {
        bit.assign (n + 1, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int k, int x) {
        for (int i = k; i <= n; i += lowbit (i)) {
            bit[i] += x;
        }
    }

    int sum (int k) {
        int res = 0;
        for (int i = k; i >= 1; i -= lowbit (i)) {
            res += bit[i];
        }

        return res;
    }
};

struct node {
    char c;
    int x, y;
};

void ovo() {
    int n, q;
    cin >> n >> q;

    vector <int> a (n + 1);
    vector <int> b; b.reserve (n + 2 * q + 5);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        b.push_back (a[i]);
    }

    vector <node> qu (q);
    for (int i = 0; i < q; i ++) {
        cin >> qu[i].c >> qu[i].x >> qu[i].y;
        if (qu[i].c == '!') {
            b.push_back(qu[i].y);
        } else {
            b.push_back(qu[i].x);
            b.push_back(qu[i].y);
        }
    }

    sort (b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    auto id = [&] (int x) -> int {
        return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };

    int m = b.size();
    BIT bit (m + 1);
    for (int i = 1; i <= n; i ++) {
        auto pos = id (a[i]);
        bit.point_add (pos, 1);
    }

    for (int i = 0; i < q; i ++) {
        auto [opt, x, y] = qu[i];
        if (opt == '!') {
            auto p1 = id (a[x]);
            bit.point_add (p1, -1);
            auto p2 = id (y);
            bit.point_add (p2, 1);
            a[x] = y;
        } else {
            if (id(x) - 1 >= 1)
            cout << bit.sum (id (y)) - bit.sum (id (x) - 1) << '\n';
            else 
            cout << bit.sum (id (y)) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}