# 一些会用到的好用的c++


## ranges

```cpp
ranges :: sort (a | views::drop(1) | views::take(n));
//drop表示丢弃元素, 适用于1-based, take相当于sort(a.begin() + 1, a.begin() + 1 + n);

ranges::sort(a, greater<>());

ranges::reverse(a);

auto it = ranges::find(r, x);
if (it != ranges::end(r)) { /* found */ }

int c = ranges::count(r, x);

int mx = std::ranges::max(a);

int mn = std::ranges::min(a);

auto it = ranges::lower_bound(a, x);

ranges::iota(fa, 0LL);
//相当于fa[0]=0, fa[1]=1, ..., fa[n]=n, 0LL作为起始数值
```
