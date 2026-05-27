
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct BIT {
    vector <int> bit;
    int n;

    BIT (int x = 0) : n(x) {
        bit.assign (n + 5, 0);
    }

    static int lowbit (int x) {
        return (x & -x);
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit(i)) {
            bit[i] = max (bit[i], k);
        }
    }

    int sum (int x) {
        if (x < 1) return 0;

        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            ans = max (ans, bit[i]);
        }
        return ans;
    }
};

void ovo() {
    int n; cin >> n;
    vector <int> h (n + 1), a (n + 1);
    
    for (int i = 1; i <= n; i ++) {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <int> dp (n + 1);
    BIT bit (n + 1);
    
    for (int i = 1; i <= n; i ++) {
        int x = h[i];
        dp[x] = bit.sum (x - 1) + a[i];
        // cerr << "i : " << i << ' ' << x << ' ' << dp[x] << '\n';

        bit.point_add (x, dp[x]);
    }

    int mx = 0;
    for (int i = 1; i <= n; i ++) {
        mx = max (mx, dp[i]);
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}