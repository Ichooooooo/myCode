
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct BIT1 {
    vector <int> bit;
    int n;

    BIT1 (int x = 0) : n(x) {
        bit.assign (n + 5, 0);
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

struct BIT2 {
    vector <int> bit;
    int n;

    BIT2 (int x = 0) : n(x) {
        bit.assign (n + 5, 0);
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
    int n; cin >> n;
    vector <int> a (n);

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    const int N = 1e5 + 5;
    vector <int> b (n), c (n);

    BIT1 bit1 (N);
    BIT2 bit2 (N);
    for (int i = 0; i < n; i ++) {
        b[i] = bit1.sum (a[i] - 1);
        bit1.point_add (a[i], 1);

        // cerr << "i : " << i << ' ' << b[i] << '\n';
    }

    for (int i = n - 1; i >= 0; i --) {
        c[i] = n - 1 - i - bit2.sum (a[i]);
        bit2.point_add (a[i], 1);

        // cerr << "i : " << i << ' ' << c[i] << '\n';
    }

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += b[i] * c[i];
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}