---
title： 一些奇怪的tip
---

下面是我整理的平时碰到的一些奇怪的错误总结的奇怪的提示，持续更新（哈哈

## 使用排序/查找

1. lower_bound如果没有找到大于等于的值返回a.end()

2. lower_bound返回值是一个迭代器，*解值，-begin()返回序列pos, 如果结果是end(), 则pos返回最后一个下标 + 1

3. sort排序左闭右开区间

## 优先级

```cpp
cout << (x ^ pre) << ' ';
```

这里一定要加括号否则报错

## 关于内存分配

1. 数组的初始化时间复杂度是 O(1) ，vector是O(n)

2. vector<int> 比 vector<long long>能开更大的数组,因为int的内存比long long 小

3. vector<bool>因为某些神奇原因会导致程序变慢

4. vecotr如果你需要push进东西的话,可以提前`reserve(n)` 

- 本质上就是一次 **内存分配**，复杂度是 **O(1)**（严格来说是 O(n) 的内存分配，但没有逐元素初始化）用 `reserve` 可以一次性分配好空间，避免多次扩容和数据搬迁

5. 在大数据量输出场景下，**`endl` **会因为强制刷新导致超时。用`'\n'` **更快**,因为endl 实时输出

## O2优化

##### 不开优化可能 TLE 的典型情况：

- 用 `vector<bool>` 做标记数组。

- 大循环里频繁调用小函数。

- 重复计算没有手动消除。

- 大量输出用 `endl`。

- 使用 STL 的慢接口（如 `.at()`）。

- 大数组访问模式不友好。

在比赛里，**默认开** `-O2` 是必须的，它能帮你自动解决很多卡常问题。 

- 编译器选项中添加：g++ main.cpp -o main -O2 -std=c++23

## 手动实现向上/下取整

#### 向下取整（数学 floor）

```cpp
long long floordiv(long long a, long long b) {
    if (a >= 0) return a / b;
    return - ((-a + b - 1) / b);
}
```

#### 向上取整（数学 ceil）

```cpp
long long ceildiv(long long a, long long b) {
    if (a >= 0) return (a + b - 1) / b;
    return - ((-a) / b);
}
```

## 环形数组（1-based）

```cpp
// j ∈ [1, n]
prev = (j - 1 + n - 1) % n + 1;
next = j % n + 1;
```

## 初始化数组

**memset 快但挑值，fill 稳且万能。**

其中menset后面sizeof只能传入数组本身

```
memset(dp, 0, sizeof dp)	//全 0， 最快
memset(dp, -1, sizeof dp)		//只能初始化为0，-1
fill(dp, dp+n, 0)	// 可以设置成任何数
```


## 关于int函数返回值

```cpp
int fc() {
	return re[x][y][time] = 0;
}
```

```
(a = b)
```

是一个 **表达式**，并且：

> **整个表达式的值 = 右值 b**
>
> **等价写法：**
>
> ```
> cpp复制代码re[x][y][time] = 0;
> return 0;
> ```
>
> 完全一致。

## 我的若只错误

- 变量名重复，按照顺序命名a，b，c，d

- 多测和mod可能混淆，注意某样例之后检查多测
- 标准c++中不能用变长数组，也就是a[N]，中N只能是一个**「编译期常量」**，即const类型，2 * N同样合理
- printf和cout，cin和scanf均不能混用，在关闭c++流的情况下

```cpp
    ios::sync_with_stdio(false);	
//关闭 C++ 流 (cin/cout) 与 C 标准 IO (scanf/printf) 的同步，以提升 IO 速度
    cin.tie(0);	
//cin 绑定 cout,每次 cin >> 前，都会 自动刷新 cout
```

## 输出的时候转义字符

| 想要输出的字符 | 实际写法 | 说明                                                         |
| -------------- | -------- | ------------------------------------------------------------ |
| `\`            | `\\`     | 反斜杠本身是转义符号，需要写两次                             |
| `"`            | `\"`     | 在字符串字面量中输出双引号                                   |
| `'`            | `\'`     | 在字符字面量或字符串中输出单引号                             |
| `?`            | `\?`     | 避免和三字母词(trigraph)冲突（现代编译器一般已废弃，但仍保留写法） |
| 换行           | `\n`     | 光标移到下一行开头                                           |

## 可能用到的数学公式

$$
1^2+2^2+...+n^2=n*(n+1)*(2*n+1)/6
$$

## 常用常数
**二进制转十进制** 
$2 ^ {10} \approx 10 ^ 3, 2 ^{60} \approx 10 ^ {18}$

**数据类型**
|$int$ | 32位 | $2 ^{32}$ | $2e9$ |
| --- | --- | --- | --- |
|$long long$ | 64位 | $2 ^ {64}$| $9e18$ |

**数据范围**
- LLONG_MIN = $-2^{63}$

- LLONG_MAX = $2^{63}-1$

## _int128

### 1) 什么时候用
- 中间乘法/累加可能超过 `long long`（> 9e18）时用来防溢出
- 典型：`a*b`、`cnt0*cnt1`、`ans += big * (1<<k)` 这类

---

### 2) 关键原则：先提升类型再运算
> 只在“接收变量”用 __int128 不够，必须让**表达式本身**在 128 位里算，否则会先用 long long 溢出。

✅ 正确：
```cpp
__int128 x = (__int128)a * b;     // 乘法在 128 位里
__int128 y = (__int128)cnt0 * cnt1 - sumB;
```

### 3) 输入

```cpp
long long t;
cin >> t;
__int128 x = t;
```

### 4) 输出

#### 方案一 : 最终结果在long long内
```cpp
long long out = (long long)ans;
cout << out << "\n";
```

#### 方案二 : 通用打印函数
```cpp
void print128(__int128 x){
    if(x==0){ cout<<0; return; }
    if(x<0){ cout<<'-'; x=-x; }
    string s;
    while(x>0){
        int d = x % 10;
        s.push_back('0'+d);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

print128(ans);
cout << "\n";
```

## cout输出

cout 直接输出 double 默认是 6 位有效数字，不是小数点后 6 位。
