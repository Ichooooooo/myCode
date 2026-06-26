
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

const int INF = 1e12;
const int N = 2e5 + 10;
int a[N];

struct BIT {
    vector <int> bit;
    int n;

    BIT (int x = 0) : n(x) {
        bit.assign (n + 5, INF);
    }

    static int lowbit (int x) {
        return (x & -x);
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit(i)) {
            bit[i] = min (bit[i], k);
        }
    }

    int sum (int l, int r) {
        int res = INF, rt = r;

        cerr << '\n';
        while (rt >= l) {

            // cerr << rt << ' ' << lowbit (rt) << '\n';

            if (rt - lowbit (rt) + 1 < l) {
                res = min (res, a[rt]);
                rt--;
            } else {
                res = min (res, bit[rt]);
                rt -= lowbit (rt);
            }
        }

        return res;
    }
};

void ovo() {
    int n, q;
    cin >> n >> q;

    BIT bit (n);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        bit.point_add (i, a[i]);
    }

    while (q --) {
        int l, r;
        cin >> l >> r;

        cout << bit.sum (l, r) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}