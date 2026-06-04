// trick : 离线处理

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
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

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int m; cin >> m;
    vector <arr3> b (m);

    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        b[i][0] = r, b[i][1] = l; b[i][2] = i;
    }

    const int INF = 1e6 + 5;
    sort (b.begin(), b.end());

    vector <int> last (INF);
    vector <int> ans (m);
    int pos = 1, nowr = b[0][0];
    
    BIT bit (n);
    for (int i = 0; i < m; i ++) {
        auto [r, l, x] = b[i];

        for (int j = pos; j <= r; j ++) {
            if (last[a[j]] == 0) {
                last[a[j]] = j;
                bit.point_add (j, 1);
            } else {
                bit.point_add (last[a[j]], -1);
                last[a[j]] = j;
                bit.point_add (j, 1);
            }
        }

        pos = r + 1;
        ans[x] = bit.sum (r) - bit.sum (l - 1);
    }

    for (int i = 0; i < m; i ++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}