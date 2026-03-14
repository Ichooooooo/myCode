# 最大公约数

## gcd性质

**同余相关** 
$a_i \equiv a_i (mod) k \Leftrightarrow k | (a_i - a_1) $ 即如果两数同余与$k$, 那么$k$ 整除两数差值
- $gcd (x, y) = gcd (x, y - x)$

**运算性质**
- $gcd (a, b) = gcd (|a|, |b|) $
- $gcd (a, 0) = |a|$
- $gcd (0, 0) = 0 $
- $lcm (a, b) = lcm(|a|, |b|) $
- $lcm (a, 0) = |a| $

**异或不等式**
$$
(x - y) <= (x \oplus y) <= (x + y)
$$

**时间复杂度**
$gcd$ 的时间复杂度是 $O(log(min(a, b))) $, 更粗略写$O(log(max(a, b))) $