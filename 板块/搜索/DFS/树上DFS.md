## 基础板子

**树上$DFS$一次性维护信息**
$g$ : 邻接矩阵存储边的信息
$dep$ : 结点的深度
$fa$ : 父节点
$siz$ : 子节点个数

```cpp
const int N = 200000 + 5;
vector<int> g[N];
int n;
int fa[N], dep[N], siz[N];

void dfs(int u, int p){
    fa[u] = p;                 // 记录父亲
    dep[u] = dep[p] + 1;       // 深度：根 dep[1]=1（dep[0]=0 作为哨兵）
    siz[u] = 1;                // 子树大小先算自己

    for(int v : g[u]){
        if(v == p) continue;   // 无向边防止走回父亲
        dfs(v, u);             // 先把孩子子树算完（后序关键）
        siz[u] += siz[v];      // 再把孩子子树大小累加到 u
    }
} 

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++){
        g[i].clear();
    }

    for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dep[0] = 0;            // 哨兵
    dfs(1, 0);             // 根为 1，父亲设 0
}
```

## [应用](https://ac.nowcoder.com/acm/contest/126634/E)

### 基本考点

树上DFS + 数学推理

### 基本思路

本来问题只是求解所有的树上结点$(u, v)$的距离$dis$之和, 暴力需要优化, 把两个点的思想转化为边的思想, 然后发现一个点$v$和他的父节点$u$构成的线段可以定量$O(1)$求解贡献度, 即
$$
ans1 = (n - siz(v)) \times siz(v)
$$
但是题目要求当$u$, $v$存在祖先后代关系的时候,$dis$为1, 设$disp$为存在祖先后代关系的$(u, v)$的$dis$之和, $m$为存在祖先后代的$(u, v)$的对数,那么式子
$$
ans2 = ans1 - disp + m 
$$
而$disp$还是优化暴力, 用点的角度看, 每个结点和父节点的距离从$1, 2, 3... dep - 1$, 等差数列求和有
$$
disp = \sum_{i = 1}^{dep - 1} i
$$
显然
$$
m = \sum_{i = 1} ^ n (siz[i] - 1)
$$


```cpp
int fa[N], siz[N], dep[N];
vector <int> g[N];

void solve(){   
    int n;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        g[i].clear();   //多测
    }

    int a, b;
    for (int i = 1; i < n; i ++) {  //注意n个点, n - 1条边
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto dfs = [&] (int u, int f, auto self) -> void {
        dep[u] = dep[f] + 1;
        fa[u] = f;
        siz[u] = 1;
        
        for (auto v : g[u]) {
            if (v == f) continue;
            self(v, u, self);
            siz[u] += siz[v];
        }
    };

    dfs(1, 0, dfs);

    int dist = 0, disp = 0, m = 0, ans = 0;
    for (int i = 1; i <= n; i ++) {
        dist = (dist + (siz[i] * (n - siz[i]) % mod)) % mod; //累加也要取模
    }
    
    for (int i = 1; i <= n; i ++) {
        disp = (disp + (dep[i] * (dep[i] - 1) ) / 2 % mod) % mod;
    }

    for (int i = 1; i <= n; i ++) {
        m = (m + (siz[i] - 1)) % mod;
    }

    ans = (dist - disp + m) % mod;
    ans = (ans + mod) % mod; //防止z负数
    cout << ans << endl;
}
```