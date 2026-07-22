// 最开始没有思路, 因为不知道怎么求二维的和
// 1. 二维的矩阵和总是拆成四个二维前缀做运算求 2. 然后二维图拆成了点对, 发现依旧从小到大排序控制l, 然后树状数组统计r 3.优化的时候注意尽量少的使用多余map
// 遇到二维矩阵的时候想起来

#include <bits/stdc++.h>
#define int long long
using namespace std;
#define sz(x) ((int)(x).size())
using arr2 = array<int, 2>;
using arr4 = array<int, 4>;

struct BIT {
    int n;
    vector<int> bit;

    BIT(int n) : n(n) {
        bit.assign(n + 5, 0);
    }

    int lowbit(int x) {
        return x & -x;
    }

    void point_add(int k, int x) {
        for (int i = k; i <= n; i += lowbit(i)) {
            bit[i] += x;
        }
    }

    int sum(int x) {
        int res = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            res += bit[i];
        }
        return res;
    }
};

struct node {
    int x, y;
    int id; 
    int coef;
};

void ovo() {
    int n, m;
    cin >> n >> m;

    vector<arr2> a(n);
    vector<int> b;

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        b.push_back(a[i][1]);
    }

    sort(a.begin(), a.end());

    vector<arr4> qu(m);

    vector <node> rq;
    for (int i = 0; i < m; i ++) {
        auto &[x, y, z, k] = qu[i];
        cin >> x >> y >> z >> k;

        // 需要用到 F(z, k), F(x - 1, k), F(z, y - 1), F(x - 1, y - 1)
        b.push_back(k);
        b.push_back(y - 1);
        rq.push_back ({z, k, i, 1});
        rq.push_back ({x - 1, k, i, -1});
        rq.push_back ({z, y - 1, i, -1});
        rq.push_back ({x - 1, y - 1, i, 1});
    }

    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    auto id = [&](int x) -> int {
        return lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    };

    sort (rq.begin(), rq.end(), [] (node & x, node & y) {
        return x.x < y.x;
    }); 

    // for (int i = 0; i < rq.size(); i ++) {
    //     cerr << rq[i].x << ' ' << rq[i].y << ' ' << rq[i].id << ' ' << rq[i].coef << '\n';
    // }

    vector <int> ans (m);
    BIT bit ((int)(b.size()));

    int now = 0;
    for (int i = 0; i < sz(rq); i ++) {
        while (now < n && a[now][0] <= rq[i].x) {
            // cerr << "id : " << id(a[now][1]) << '\n';
            bit.point_add (id(a[now][1]), 1);
            now++;
        } 

        ans[rq[i].id] += rq[i].coef * bit.sum (id(rq[i].y));
    }

    for (int i = 0; i < m; i ++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;

    while (_--) ovo();
}