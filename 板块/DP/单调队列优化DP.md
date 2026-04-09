# 单调队列优化DP

## 场景
给定一个长度为 $n$ 数组 $a$, 因为题目要求会导致 dp 只能从一个区间范围转移过来, 并且因为贪心求解max or min导致有单调性

## 思路

维护单调队列 $deque$ , 通过下标条件维护范围dp, 通过比较dp的值维护单调性

## 基础代码

```cpp
    deque <arr2> dq;
    dq.push_back ({dp[1], 1});

    for (int j = 2; j <= m; j ++) {
        // 通过下标维护范围dp
        while (dq.size() && j - dq.front()[1] - 1 > d) {
            dq.pop_front();
        }

        // 因为单调性, 这时候队头是极小/极大值
        if (dq.size()) {
            dp[j] = dq.front()[0] + a[i][j] + 1;
        }

        // 通过值维护队列单调性, >= 是因为相同值的情况下, 因为范围限制, 靠后的值更容易被后面取到
        while (dq.size() && dq.back()[0] >= dp[j]) {
            dq.pop_back();
        }

        dq.push_back ({dp[j], j});
        }
```

## 基础应用

### A
[基础应用](https://codeforces.com/contest/1941/problem/E)

#### 基本题意

有 $n$ 个长度为 $m$, 相互独立的数组. 对于每一个数组a, 要求数组头尾 $a_0$ 和 $a_{m - 1}$ 必须选, 任意两个被选择的 $a_i$距离不得超过 $d$, 距离计算为 $| i - j | - 1$ 被选择的 $i$ 成本为 $a_i$, 求 这多个数组中连续 $k$ 个数组的成本最小值

#### 基本思路

1. 考虑dp状态设置为 $dp_i$ 为当前 $i$ 位置必须选择, 则转移为
$$
dp_i = min_{(i - j - 1 \leq d)} (dp_j + a[i])
$$

2. 那么现在的dp有两个特点

- 转移有范围
- 单调性, 需要维护范围内的 $min$
- 首尾两端必须选, 则最后转移到 $m$ 即可

考虑单调队列维护

#### 基本代码

```cpp
    vector <int> ans (n + 1);
    for (int i = 1; i <= n; i ++) {

        // 每一个a_i独立维护deque
        vector <int> dp (m + 1);
        dp[1] = a[i][1] + 1;
        deque <arr2> dq;

        // 首尾必须选
        dq.push_back ({dp[1], 1});

        for (int j = 2; j <= m; j ++) {
            while (dq.size() && j - dq.front()[1] - 1 > d) {
                dq.pop_front();
            }

            if (dq.size()) {
                dp[j] = dq.front()[0] + a[i][j] + 1;
            }

            while (dq.size() && dq.back()[0] >= dp[j]) {
                dq.pop_back();
            }

            dq.push_back ({dp[j], j});
        }

        ans[i] = dp[m];
    }

    int bas = 0;
    for (int i = 1; i <= k; i ++) {
        bas += ans[i];
    }

    // 滑动窗口维护连续k个
    int an = bas;
    for (int i = k + 1; i <= n; i ++) {
        int now = bas + ans[i] - ans[i - k];
        an = min (an, now);

        bas = now;
    }

    cout << an << '\n';
```

### B
[范围变化维护](https://qoj.ac/download.php?type=attachments&id=1247&r=1)

#### 基本题意

给定一个长度为 $n$ 数组 $a$, 给定 $m$ 个区间 $l_i$, $r_i$, 要求每个区间内必须存在一个被选择的 $a_i$, 产生成本 $a_i$, 求最小总成本

#### 基本思路

1. 考虑维护dp, 使得 $dp_i$ 表示每一个 $a_i$ 都必须被选且所有 $r_i \leq i$ 的区间都满足条件, 考虑转移
$$
dp_i = min_{dp_j} + a_i
$$
- 其中 $i$ 和 $j$ 之间不能存在完整区间
- 因为最后一个位置 $n$ 不一定会选, 所以我们 dp 到 $n + 1$

2. 那么难点在于怎么维护 $min_{dp_j}$ 

- 首先我们注意到, 只有当 $r_j < i$ 的时候区间才有可能完整存在于 $i$ 和 $j$ 之间, 所以先通过右端点限制我们需要考虑的区间, 那么很明显,  我们选取 $dp$ 转移最小只能这些区间里 $max_{l_j}$

- 又有两个相邻右端点 $r_j$, $r_{j + 1}$ 间的 $i_{(i > r_j, i \leq r_{j + 1})}$ 只受到 $r_j$ 的影响, 我们可以将 $r$ 作为第一键, $l$ 第二键排序, 每次动态更新当前 $r$ 前面的 $max_l$, 并且只会从 $r + 1$ 位开始影响后面 $dp_i$ 范围选取

3. 范围 + 单调, 单调队列维护

#### 基本代码

```cpp
void ovo() {       
    int n; cin >> n;
    vector <int> a (n + 2);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector <arr2> b; b.reserve(m);

    // 对区间排序
    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        b.push_back ({r, l});
    }

    vector <int> c (n + 2);
    sort(b.begin(), b.end());
    
    int l = 0;
    for (int i = 0; i < m; i ++) {
        // 维护当前r前的最大l, 然后影响i > r 的位置范围
        l = max (l, b[i][1]);
        c[b[i][0] + 1] = l;
        
        // cerr << i << ' ' << b[i][1] << ' ' << b[i][0] << ' ' << l << '\n';
    }

    // 维护每个位置的范围
    int now = -1;
    for (int i = 1; i <= n + 1; i ++) {
        if (c[i]) {
            now = c[i];
        }  

        if (now == -1) {
            c[i] = 0;
        } else {
            c[i] = now;
        }

        // cerr << "c : " << i << ' ' << c[i] << '\n';
    }

    vector <int> dp (n + 2);
    deque <arr2> dq;

    // 细节1 : 我们维护的dp是 当前位置必须选, 所以最开始可能从 位置0, 代价0开始转移
    dq.push_back({0, 0});

    a[n + 1] = 0;

    // 细节2: 一直维护到n + 1
    for (int i = 1; i <= n + 1; i ++) {

        // 范围维护
        while (dq.size() && dq.front()[1] < c[i]) {
            dq.pop_front();
        }

        if (!dq.empty()) {
            dp[i] = dq.front()[0] + a[i];
        }

        while (dq.size() && dq.back()[0] >= dp[i]) {
            dq.pop_back();
        }

        dq.push_back ({dp[i], i});
        // cerr << "dp : " << dp[i] << '\n';
    }

    cout << dp[n + 1] << '\n';
}

```

