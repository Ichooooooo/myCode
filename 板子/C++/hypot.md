# hypot

## 用途
计算欧几里德长度, 常用于两点之间距离, hypot(x, y, z) = sqrt(x*x + y*y + z*z)

## 用法
```cpp
pq.emplace(hypot(x[i], y[i]) - hypot(x[i],y[i] - 1), i);
```