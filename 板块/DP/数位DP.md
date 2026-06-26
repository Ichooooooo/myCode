# 数位DP

## 总结
- 把数字拆成一位一位。
- 从高位往低位填。
- 用 tight 保证不超过 N。
- 用 state 记录题目需要的信息。
- 用 started 处理前导零。
- 最后 solve(R) - solve(L - 1)。

## 基本版

### 计算位数不含某数字

#### 题意
统计 $x$ 中 不含数字 $y$ 的数有多少个. `统计 0 ~ 25 中 不含数字 4 的数有多少个`

#### 基本思路

- 先把 $x$ 看作字符串, 然后就开始想逐位构造结果
- 我们最大的限制实际是构造出来的数 $z$ 不能大于 $x$
- 发现对比 $x$ 和 $z$, 如果第一个不相同的数字 $x \leq z$, 就能满足条件, 所以如果前面存在满足 < 的位, 后面构造大小不受限制, 如果不满足, 受此时 $x$ 这个位的数值影响

#### 基本代码

**基本代码 :**
```cpp
ll dfs(int pos, bool tight) {
    // 构造完了所有的位数, 个位数每个值都是一种方案
    if (pos == digit.size()) return 1;

    // 用tight 标记前面是否已经存在小于的位数了
    int up = tight ? digit[pos] : 9;
    ll res = 0;

    for (int d = 0; d <= up; d++) {
        if (d == 4) continue; // 题目条件
        // dfs求结果
        res += dfs(pos + 1, tight && d == digit[pos]);
    }

    return res;
}
```

**记忆化 :**

思路 : 如果当前已经不受上界限制，那这个状态可以复用。, 比如25, 十进制位 1, 0 后面都不受限制, 0~9都能选, 结果相同

```cpp
ll memo[20];
bool vis[20];

ll dfs(int pos, bool tight) {
    if (pos == digit.size()) return 1;

    if (!tight && vis[pos]) return memo[pos];

    int up = tight ? digit[pos] : 9;
    ll res = 0;

    for (int d = 0; d <= up; d++) {
        if (d == 4) continue;
        res += dfs(pos + 1, tight && d == digit[pos]);
    }

    if (!tight) {
        vis[pos] = true;
        memo[pos] = res;
    }

    return res;
}
```

### 应用

[数位DP] (https://atcoder.jp/contests/dp/tasks/dp_s)

#### 题意
在 1 和 K （包括 K ）之间找到满足以下条件的整数的数量，模 1e9 +7 ：十进制数字的和是 D 的倍数

#### 代码
```cpp
void ovo() {
    string s; cin >> s;
    int d; cin >> d;
    
    int n = s.size();
    vector <int> a (n + 5);
    for (int i = 0; i < n; i ++) {
        a[i] = s[i] - '0';
    }

    vector <vector <int> > dp (n + 5, vector <int> (d + 5)), vis (n + 5, vector <int> (d + 5));
    
    auto dfs = [&] (auto self, int pos, int sum, bool tight) -> int {
        if (pos == n) return sum == 0;

        if (!tight && vis[pos][sum]) return dp[pos][sum];

        int up = (tight ? a[pos] : 9);

        int ans = 0;
        for (int i = 0; i <= up; i ++) {
            ans = (ans + self (self, pos + 1, (sum + d - i % d) % d, (tight && (i == a[pos])))) % mod;
        }

        if (!tight && !vis[pos][sum]) {
            dp[pos][sum] = ans;
            vis[pos][sum] = 1;
        }

        return ans;
    };

    int ans = dfs(dfs, 0, 0, true);

    cout << (ans - 1 + mod) % mod << '\n';
}
```

#### 常见坑点

1. dfs 的含义没统一

dfs含义是 从第 pos 位开始往后填，前面的状态已经由 sum / tight 记录好了, 所以dfs(0, 0, true) 就是开始位置, 不需要额外枚举第一位

2. 终止条件错误

if (pos == n) return sum == 0;
所有位填完了，如果数位和模 d 等于 0，就贡献 1，否则贡献 0。

3. tight 没有参与记忆化判断
dp[pos][sum] 其实只记录 tight = 0的状态
if (!tight && vis[pos][sum]) return dp[pos][sum]; 记忆化也只缓存tight == false 的状态

4. 取模运算
(sum + d - i % d) % d 一定要先把i % d否则就算加上d 可能也避免不了负数

5. 转移方程

- ans = (ans + self (self, pos + 1, (sum + d - i % d) % d, (tight && (i == a[pos])))) % mod;
- 最后结束 : if (pos == n) return sum == 0;

反向计算答案, 意思是我需要 sum 的值, 该怎么通过之后的状态加上这次选择得到, 统计结果

- ans = (ans + self(self, pos + 1, (sum + i) % d, tight && i == up)) % mod;
- 最后结束 : if (pos == n) return sum == 0;
  
正向计算答案, 意思是在已经填了前 pos 位、当前数字和余数为 sum 的情况下， 后面所有填法中，有多少个最终合法

6. 时间复杂度

for (int d = 0; d <= up; d++)
最多枚举 0~9，也就是 10 次。
所以：O(状态数×每个状态转移)=O(L×10)




