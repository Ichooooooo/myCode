# 汉诺塔问题

**基本思路** 
1. 要移动最大盘（第n 个）从 A 到 C，必须先把上面 n−1 个全部移走到 B（否则大盘被压住）。这至少需要 f(n−1) 步。

2. 移动最大盘一次：+1 步。

3. 再把那 n−1 个从 B 移到 C（借助 A），至少再要 f(n−1) 步。

**递归时间**
$$ f(n)≥2f(n−1)+1, f(n)=2f(n−1)+1,f(1)=1⇒f(n)=2n−1$$

```cpp
void f(int n, char a, char b, char c) {
    if (n == 0) {
        return;
    }
    else {
        f(n - 1, a, c, b);
        cout << a << " " << c << endl;
        f(n - 1, b, a, c);
    }
}

void solve() {
    int n;cin >> n;
    f(n, 'A', 'B', 'C');
}
```