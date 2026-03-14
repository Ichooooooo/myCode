# 0-1BFS

## 使用场景
当边权为0, 1, 求非负权最短路

## 基本步骤
- 维护 dist[x] = 到达 x 的最小代价
- 用 deque 模拟“按 dist 从小到大弹出”的过程：
    若走 0 边：dist 不变，优先级最高，push_front
    若走 1 边：dist +1，优先级稍低，push_back

## 基本思路
deque 里从前到后，dist 非递减（或者至少“队首总是当前最小 dist 的候选”）。

## 连接

### 与基本BFS相比
BFS 用 vis 一次入队就结束（因为第一次到达即最短步数）

### 与Dijkstra相比
1. Dijkstra：适用于非负权，用优先队列，每次取最小 dist 的点。

2. 0-1 BFS：当边权只有 0/1 时，优先队列的“加权排序”可以被 deque 的“前插/后插”模拟掉。

## 时间复杂度
- 0-1 BFS 的时间复杂度: $O(V+E)$, 简化成$O(N \times M)$
1. 主要来自“扫描每条边做松弛判断”(≈E 次), E = 4 * V代表边个数
2. O(V) 那一项本质是每个点被“弹出处理/初始化”等固定开销，写成 O(V+E) 是最常见的统一表述

## 应用
[0-1BFS](https://atcoder.jp/contests/awc0012/tasks/awc0012_d)

```cpp
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];

    const int INF = 1e9;

    vector<vector<int>> dist(N, vector<int>(M, INF));

    deque<pair<int,int>> dq;
    dist[0][0] = 0;
    dq.push_back({0, 0});

    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};

    while (!dq.empty()) {
        auto [r, c] = dq.front();
        dq.pop_front();

        // 注意：这里不需要 vis。
        // 因为可能先以较大代价到达，之后还能被更小代价松弛更新。
        // 0-1 BFS 的正确性来自“每次从队首取出的点，其 dist 已是当前最小候选”。

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            // 边权：走到通道 0；走到墙 1（砸墙）
            int w = (S[nr][nc] == '#') ? 1 : 0;

            // 标准最短路松弛
            if (dist[r][c] + w < dist[nr][nc]) {
                dist[nr][nc] = dist[r][c] + w;

                // 关键：根据 w 决定插入 deque 的哪一端
                // w=0：距离不增，应该尽快被处理 => 放队首
                // w=1：距离增 1，优先级低一些 => 放队尾
                if (w == 0) dq.push_front({nr, nc});
                else dq.push_back({nr, nc});
            }
        }
    }

    cout << dist[N-1][M-1] << "\n";
    return 0;
}
```

