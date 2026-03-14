# CMP

## lamda内置
```cpp
sort(v.begin(), v.end(), [&](const Node& x, const Node& y){
    if (x.a != y.a) return x.a < y.a;
    if (x.b != y.b) return x.b > y.b;
    return x.id < y.id;
});
```

## struct内置
```cpp
struct Node {
    int a, b, id;
    bool operator<(const Node& other) const {
        if (a != other.a) return a < other.a;      // a 升序
        if (b != other.b) return b > other.b;      // b 降序
        return id < other.id;                      // id 升序
    }
};
```
### Attention
set/map 判断“相同 key”不是靠 ==，而是靠： **!comp(x,y) && !comp(y,x)** 比较器返回结果不同

