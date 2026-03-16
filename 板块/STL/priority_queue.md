# priority_queue

## 基本使用

- `priority_queue<T, Container, Compare>`
- `priority_queue<T, vector<T>, Cmp> pq;`

```cpp
// 基本用法, 从大到小
priority_queue<long long> pq;
// 从小到大
priority_queue<long long, vector<long long>, greater<long long>> pq;
```

- `Container = vector<T>`：底层容器用 `vector`, 其中`T = pair<ll,int>或者int`是pq中存储的数据类型

- `Compare = greater<pair<ll,int>>`：比较器用 `greater`， 还可以自定义cmp