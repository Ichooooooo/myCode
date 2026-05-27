
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;
const int N = 5e4 + 5;

struct BIT1 {
    int n;
    vector <int> bit;

    BIT1 (int x) : n (x) {
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

struct BIT2 {
    int n;
    vector <int> bit;

    BIT2 (int x) : n (x) {
        bit.assign (n + 5, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit(i)) {
            bit[i] = (bit[i] + k) % mod;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit (i)) {
            ans = (ans + bit[i]) % mod;
        }
        return ans;
    }
};


void ovo() {
    int n; cin >> n;

    vector <arr2> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort (a.begin(), a.end());

    BIT1 bit1 (N);
    BIT2 bit2 (N);

    int ans = 0, pre = 0;
    for (int i = 0; i < n; i ++) {
        auto [v, x] = a[i];
        int cn1 = bit1.sum (x);
        int tpos = bit2.sum (x);

        // cerr << v << ' ' << x << '\n';
        // cerr << "i : " << i << ' ' <<  cn1 << ' ' << tpos << '\n';

        int an = v * ((cn1 * x - tpos + (pre - tpos) - (i - cn1) * x + mod) % mod) % mod;

        ans = (ans + an) % mod;
        // <= 
        bit1.point_add (x, 1);
        bit2.point_add (x, x);
        pre = (pre + x) % mod; 

        // cerr << "pre : " << pre << '\n';
        // cerr << "an : " << an << '\n';
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}