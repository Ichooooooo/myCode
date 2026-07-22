// 题目理解错了, 然后没有仔细分析拓扑序, 导致想从大到小转移
// 实际上是 l从大到小排序限制条件, 然后 统计r 关系即可
// 二维偏序计数, 对每个区间 [l, r]，数有多少区间 [L, R] 满足l < L 且 R < r

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

    int sum (int r) {
        int res = 0;
        for (int i = r; i >= 1; i -= lowbit (i)) {
            res += bit[i];
        }

        return res;
    }
};

void ovo() {
    int n; cin >> n;

    vector <arr3> a (n);
    vector <int> b; b.reserve (2 * n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];

        a[i][2] = i;
        b.push_back(a[i][0]);
        b.push_back(a[i][1]);
    }

    sort (a.rbegin(), a.rend());
    sort (b.begin(), b.end());
    b.erase (unique(b.begin(), b.end()), b.end());
    auto id = [&] (int x) -> int {
        return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };

    int m = b.size();
    BIT bit (m);
    vector <int> ans (n);
    for (int i = 0; i < n; i ++) {
        auto [l, r, p] = a[i];

        // cerr << r << ' ' << id (r) << '\n';
        if (id(r) - 1 > 0)
        ans[p] = bit.sum (id(r) - 1);
        
        // cerr << bit.sum (id(r) - 1) << '\n';
        bit.point_add (id(r), 1); 
    }

    for (int i = 0; i < n; i ++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}