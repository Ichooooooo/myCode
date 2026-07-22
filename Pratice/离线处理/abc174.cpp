// 第一眼想统计颜色有没有, 发现无法同时让l, r都有单调性
// 实际上应该统计不同颜色出现位置, 查询按照右端点排序, 每次更新颜色的最后位置
// 遇到统计种类的注意, last + BIT

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
    int n, q; 
    cin >> n >> q;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <arr3> qu (q);
    for (int i = 0; i < q; i ++) {
        auto & [r, l, p] = qu[i];
        cin >> l >> r;
        p = i;
    }

    // 实际上可以直接用vector存储共用一个左端点的区间, 节省nlog
    sort (qu.begin(), qu.end());

    vector <int> ans (q);
    vector <int> last (n + 1);
    BIT bit (n);

    int now = 1;
    for (int i = 0 ; i < q; i ++) {
        auto [r, l, p] = qu[i];

        // cerr << r << ' ' << l << ' ' << p << '\n';
        
        while (now <= r) {
            if (last[a[now]]) {
                bit.point_add (last[a[now]], -1);
            }
            bit.point_add (now, 1);
            last[a[now]] = now;
            now++;
        }

        ans[p] = bit.sum (r);

        if (l - 1 > 0) {
            ans[p] -= bit.sum (l - 1);
        }
    }

    for (int i = 0; i < q; i ++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}