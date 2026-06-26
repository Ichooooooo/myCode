
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
        for (int i = k; i <= n; i += lowbit(i)) {
            bit[i] += x;
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
    vector <int> a (n + 1), b (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort (b.begin() + 1, b.end());
    b.erase (unique (b.begin() + 1, b.end()), b.end());

    for (int i = 1; i <= n; i ++) {
        a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
    }

    vector <int> dp (n + 1, 1);
    BIT bit (n);

    for (int i = 1; i <= n; i ++) {
        dp[i] = (dp[i] + bit.sum (a[i] - 1)) % mod;
        bit.point_add (a[i], dp[i]);
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = (ans + dp[i]) % mod;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}