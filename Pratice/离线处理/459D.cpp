// 看错题目条件固定了 ai 和 i位置, 还有 aj 和 j位置
// 转移顺序 : 从左往右
// 维护 : 维护 f(1, i, ai) 的数值在树状数组上的分布, 然后自然统计 fi > fj
// 模型 : 正常的 排序固定一维条件之后, 数据结构统计
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
    vector <int> a (n), b (n);

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort (b.begin(), b.end());
    b.erase (unique (b.begin(), b.end()), b.end());

    int m = b.size();
    vector <int> cnt1 (m), cnt2 (m);
    auto id = [&] (int x) -> int {
        return lower_bound (b.begin(), b.end(), x) - b.begin();
    };

    vector <int> L (n), R (n);

    for (int i = 0; i < n; i ++) {
        L[i] = cnt1[id(a[i])] + 1;
        cnt1[id(a[i])]++;
    }

    for (int i = n - 1; i >= 0; i --) {
        R[i] = cnt2[id(a[i])] + 1;
        cnt2[id(a[i])]++;
    }

    BIT bit (n);

    int ans = 0;
    
    bit.point_add (L[0], 1);
    for (int j = 1; j < n; j ++) {
        ans += bit.sum (n) - bit.sum (R[j]) ;

        bit.point_add (L[j], 1);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}