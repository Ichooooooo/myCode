# map

## 基本

1. map有序, 默认按照`less`key升序排列, 可以修改比较器

```cpp
map<long long, long long, greater<long long>> mp;

map<long long, long long, Cmp> mp;
```