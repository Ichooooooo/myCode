# Dijkstra算法

## 基础板子

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int w;
};

// 单源最短路：非负边权 -> Dijkstra
// 返回 dist[1..n]，dist[src]=0
// src 是单源最短路的起点 
struct Edge {
    int to;
    int w;
};

// 单源最短路：非负边权 -> Dijkstra
// 返回 dist[1..n]，dist[src]=0
// 并通过 parent 用于回溯路径：parent[v] = 从哪个点走到 v（最短路树上的父亲）
// 若目标点是 t，可用 get_path(t, parent) 输出路径
vector<int> dijkstra(int n, int src, const vector<vector<Edge>>& g,
                     vector<int>& parent) {
    vector<int> dist(n + 1, INF);
    parent.assign(n + 1, -1);              // -1 表示尚未确定父节点
    parent[src] = src;                     // 起点的父亲设为自己，便于回溯终止

    // 小根堆：按距离从小到大取
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;v
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        // 懒删除：堆里可能有过期条目
        if (d != dist[u]) continue;

        // 用 u 去松弛所有 u->v
        for (const auto &e : g[u]) {
            int v = e.to;
            int nd = d + e.w;              // 走到 v 的新距离
            if (nd < dist[v]) {
                dist[v] = nd;
                parent[v] = u;             // 记录：v 的最短路来自 u
                pq.push({nd, v});
            }
            // 若你想在最短路有多条时固定选某条（比如字典序更小），可在 nd==dist[v] 时加 tie-break
        }
    }
    return dist;
}

// 从 parent 回溯 src->t 的路径
// 若不可达（parent[t]==-1），返回空
vector<int> get_path(int src, int t, const vector<int>& parent) {
    if (t < 0 || t >= (int)parent.size()) return {};
    if (parent[t] == -1) return {};        // 不可达
    vector<int> path;
    int cur = t;
    while (true) {
        path.push_back(cur);
        if (cur == src) break;
        cur = parent[cur];
        if (cur == -1) return {};          // 防御：断链
    }
    reverse(path.begin(), path.end());
    return path;
}

```
## 细节解释

### 1. C++ 的优先队列（堆）声明：

- `priority_queue<T, Container, Compare>`

- `T = pair<int,int>`：堆里存 (距离, 点编号)

- `Container = vector<pair<int,int>>`：底层容器用 `vector`

- `Compare = greater<pair<int,int>>`：比较器用 `greater`，使它变成小根堆

### 2. if (d != dist[u]) continue;（懒删除）是干什么

```cpp
auto [d,u] = pq.top(); pq.pop();
if (d != dist[u]) continue; // 旧的、过期的记录，跳过
```
**原因 :** 我们用堆的时候，同一个点 $u$ 可能会被多次入堆。

### 3. 最小路径更新具体体现在

```cpp
for (auto e : g[u]) {
    int v = e.to;
    int nd = d + e.w;          // 走到 v 的新距离
    if (nd < dist[v]) {
        dist[v] = nd;
        pq.push({nd, v});
    }
}
```

### 4. 时间复杂度

**$ O((n+m) log n)$**
- 图用邻接表存边：遍历边总共 $O(m)$ 次“松弛尝试”。

- 每次 `push/pop` 堆是 $O(log n)$。

- 懒删除会让堆里元素个数上界接近 $O(m)$，所以有的人也写 $O(m log m)$；但因为 $m ≤ n^2$，$log m = O(log n)$，通常统一写 $O(m log n)$。

## 例题

[Dijkstra + 反图](https://www.nowcoder.com/practice/2b0c636cf77d441fa96d40ac64290d39?channelPut=tracker2)

### 基本题意

某城市共有 $n$ 个路口与 $m$ 条 单向 道路（交通繁忙，均为单行道）。其中 $1$ 号路口为邮局，$2∼n$ 号路口各有一件包裹待投递。
邮递员一次只能携带一件包裹，每次从邮局取件后出发，沿道路送达对应目的地后 必须返回邮局 才能取下一件。求完成所有 $n−1$ 件投递并最终回到邮局所需的 最短总时间

### 基本思路

各个路径互不干扰, 求加权图的最短路径. 有往返情况, 往正常做, 返则把1 ~ n的路反一遍但是前进方向不变(从1 ~ n)做

**时间复杂度** : $ O((n+m) log n)$

### 代码实现
``` cpp
struct Edge 
{
    int to;
    int w;
};


void solve(){   
    int n, m;
    cin >> n >> m;
    
    vector <vector<Edge>> g (n + 1), rg (n + 1);
    int u, v, w;
    for (int i = 0; i < m; i ++) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        rg[v].push_back({u, w});
    }

    auto Dijkstra = [&] (vector <vector<Edge>> & g, int scr) -> vector <int> {
        vector <int> dist (n + 1, intONG_MAX);
        priority_queue <PII, vector<PII>, greater<PII>> pq;
        dist[scr] = 0;
        pq.push({0, scr});

        while (! pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d != dist[u]) continue;

            for (auto x : g[u]) {
                int v = x.to;
                int dis = d + x.w;
                if (dis < dist[v]) {
                    dist[v] = dis;
                    pq.push({dis, v});
                }
            }   
        }
        
        return dist;
    };

    vector <int> ag = Dijkstra (g, 1);
    vector <int> arg = Dijkstra (rg, 1);

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans = ans + ag[i] + arg[i];
    }

    cout << ans << endl;
}
```


