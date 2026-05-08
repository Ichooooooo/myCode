# 拓扑应用

## [1](https://atcoder.jp/contests/abc456/tasks/abc456_e)

### 题意

$n$ 个城市, $m$ 条无向边使得任意两个城市互相可达, 一星期 $w$ 天, 已知每个城市 $w$ 天放不放假, 求是否存在一种方式, 从第一天任选一个城市出发, 之后每到一个城市都在放假, 可以留在本城市

### 思路

如果定义 (city, day), 明显我们需要一个环, 大环小环都有可能, 让我们一直沿着环走就能一直放假, 想到拓扑判环, 然后流程

- 拓扑图怎么建: 我们有二维状态, row * w + col转为一维, 注意这道题有合理性要求, 只有放假的点能进图
- 怎么判环: 按照最终删除的点和图所有的点比较
- 合理性: 因为边按照(city, day)相连, 所以环也一定满足(city, day) -> (city', day + 1), 一定是走过完整的星期

### 代码

```cpp

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m; cin >> n >> m;
    
    vector <vector <int>> g (n + 1);
    for (int i = 1; i <= m; i ++) {
        int u, v; cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    for (int i = 1; i <= n; i ++) {
        g[i].push_back (i);
    }

    int w; cin >> w;
    vector <string> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <int> deg (n * w + 1);
    vector <vector <int> > edge (n * w + 1);

    int tot = 0;
    for (int day = 0; day < w; day ++) {
        for (int i = 1; i <= n; i ++) {
            if (a[i][day] == 'o') {
                int id = day * n + i;
                int nd = (day + 1) % w;
                tot++;

                for (auto v : g[i]) {
                    if (a[v][nd] == 'o') {
                        int vid = nd * n + v;
                        edge[id].push_back (vid);
                        deg[vid]++;
                    }
                }
            }
        }
    }

    queue <int> qu;
    int cnt = 0;
    for (int i = 0; i < w; i ++) {
        for (int j = 1; j <= n; j ++) {
            int id = i * n + j;
            if (a[j][i] == 'o' && deg[id] == 0) {
                qu.push(id);
            }
        }
    }

    while (qu.size()) {
        int u = qu.front();
        qu.pop();
        cnt++;

        for (auto v : edge[u]) {
            if (--deg[v] == 0) {
                qu.push(v);
            }
        }
    }

    if (cnt < tot) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}
```