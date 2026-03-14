# 常用lamda格式

## 递归写法

```cpp
auto dfs = [&] (int dep, auto self) -> void{
    ///
    self(dep + 1, self);
}

dfs (1, dfs);
```

## cmp函数

```cpp
//注意[&]是当函数需要引用外部变量的时候必须有
sort(v.begin(), v.end(), [&](auto &a, auto &b){
    return a < b;
});
```

## 普通函数
```cpp
auto id = [&](ll x) -> int {
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin();
};
```

