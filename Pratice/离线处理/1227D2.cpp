// 没有理解字典序 tie-break 贪心
// 转移方向 : k从小到大
// 维护 : BIT 维护哪些坐标已经被占用, 然后二分找位置
// 模型 : 离线选择 + BIT kth + 字典序贪心

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
        bit.assign (n + 5, 0);
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
        int res  = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            res += bit[i];
        }

        return res;
    }
};

void ovo() {
    int n; cin >> n;
    vector <arr2> a (n + 1);
    vector <int> b (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0];
        a[i][1] = i;

        b[i] = a[i][0];
    }

    sort (a.begin() + 1, a.end(), [](auto & x, auto & y) {
        if (x[0] != y[0]) {
            return x[0] > y[0];
        } else {
            return x[1] < y[1];
        }
    });

    int m; cin >> m;
    vector <arr3> qu (m);
    for (int i = 0; i < m; i ++)  {
        cin >> qu[i][0] >> qu[i][1];
        qu[i][2] = i;
    } 

    sort (qu.begin(), qu.end());

    BIT bit (n);
    int now = 1;

    auto check = [&] (int x) -> int {
        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (bit.sum(mid) >= x) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    };

    vector <int> ans (m);
    for (int i = 0; i < m; i ++) {
        auto [k, p, pos] = qu[i];

        // cerr << "p : " << pos << ' ' << k << ' ' << p << '\n';

        while (now <= n && now <= k) {
            auto [x, y] = a[now];

            // cerr << x << ' ' << y << '\n';
            bit.point_add (y, 1);
            now++;
        }

        int t = check(p);
        // cerr << "t : " << t << ' ' << a[t][0] << '\n';
        ans[pos] = b[t];
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