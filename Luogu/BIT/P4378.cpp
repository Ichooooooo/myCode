
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
    vector <int> a (n + 1), b (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort (b.begin() + 1, b.end());
    b.erase (unique (b.begin() + 1, b.end()), b.end());

    for (int i = 1; i <= n; i ++) {
        a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        // cerr << "i : " << a[i] << '\n';
    }

    int m = b.size();
    BIT bit (m);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = max (i - 1 - bit.sum (a[i]), ans) ;
        bit.point_add (a[i], 1);
        // cerr << "ans : " << ans << '\n';
    }

    cout << ans + 1 << '\n';

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}