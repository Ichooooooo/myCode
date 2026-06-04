
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct BIT  {
    int n; 
    vector <int> bit;

    BIT (int x) : n (x) {
        bit.assign (n + 5, 0);
    } 

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x ;i >= 1; i -= lowbit (i)) {
            ans += bit[i];
        }
        return ans;
    }
};


void ovo() {
    int n; cin >> n;
    int m = 2 * n;

    vector <arr2> a (n + 1), b (n + 1);

    for (int i = 1; i <= m; i ++) {
        int x; cin >> x;
        if (a[x][0] == 0) {
            a[x][0] = i;
            b[x][1] = i;
        } else {
            a[x][1] = i;
            b[x][0] = i;
        }
    }

    sort (a.begin() + 1, a.end());

    // for (int i = 1; i <= n; i ++) {
    //     // cerr << "i : " << i << ' ' << a[i][0] << ' ' << a[i][1] << '\n';
    // }

    BIT bit1 (m), bit2 (m);

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        auto [l, r] = a[i];
        ans += (bit1.sum (r) - bit1.sum (l));

        // cerr << bit1.sum (r) << ' ' << bit1.sum (l) << '\n';
        bit1.point_add (r, 1);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}