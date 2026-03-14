# set用法

## set的时间复杂度

插入和查询均为$$O(log m), m为此时set里面有的元素, 红黑树本质就是树的左子树和右子树

## set基本用法

1. 查询
一般用find或者count, 因为自动去重, count只会返回0或1, 两者时间几乎没差

2. 更有意思的写法
对 set：insert(x) 返回一个 pair<iterator, bool>

- .first：指向集合中该元素的迭代器（无论是新插入的还是原来就有的）

- .second：是否发生了新插入（成功插入为 true；元素已存在则为 false）

```cpp
set<pair<int, int>> st;

auto res = st.insert({r, c});
if (res.second) {
    // 之前不存在，插入成功
} else {
    // 之前已经存在，这次没插入（set 自动去重）
}
```
map也有相同用法

## set的结构体用法

```cpp
struct Node {
    int x, y;
    int frc;
    // 这里变量定义顺序也是构造顺序

    bool operator<(const Node& it) const {
        return tie (frc, x, y) < tie (it.frc, it.x, it.y);
    }
    // 1. 这里比较器就用<, 函数内如果需要升序则返回<, 降序返回>
    // 2. tie用法就是按顺序比较里面的元素决定返回值
    // 3. set由比较器决定去重, 当比较器需要比较的元素相同的时候就会直接认为相同插入失败
};

void ovo() {
    set <Node> st;

    st.insert({i, j, sum});
    // 同上, 聚合初始化, 当满足以下情况的时候可以
    // 1.没有用户自定义构造函数
    // 2.成员都能直接按顺序初始化(public)

    st.erase({xx, yy, b[xx][yy]});
}

```



