# 区间DP

## 基本思路

1. 过程量是一个局部到整体的dp, 总能把[l, r] -> [l, k] + [k + 1, r]
2. for 长度 -- for 左端点 -- for 连接点

## 基本代码

其中 $k$ 视情况而定, 可能不需要枚举

```cpp
    for (int len = 1; len <= n; len ++) {
        for (int l = 1; l <= 2 * n - len + 1; l ++) {
            int r = l + len - 1;
            
            for (int k = l; k < r; k ++) {
                dpx[l][r] = max (dpx[l][r], dpx[l][k] + dpx[k + 1][r] + pre[r] - pre[l - 1]);
                dpn[l][r] = min (dpn[l][r], dpn[l][k] + dpn[k + 1][r] + pre[r] - pre[l - 1]);
            } 
        }
    }

```