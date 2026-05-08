# Printf

## 基本格式

- printf("格式串", 变量1, 变量2, ...); 
- 可以混合输出

## 常见占位符

| 类型               | 写法          | 说明      |
| ---------------- | ----------- | ------- |
| `int`            | `%d`        | 十进制整数   |
| `long long`      | `%lld`      | 长整型     |
| `double`         | `%f`        | 浮点数     |
| `char`           | `%c`        | 字符      |
| `char[]` / C 字符串 | `%s`        | 字符串     |
| `unsigned int`   | `%u`        | 无符号整数   |
| 百分号              | `%%`        | 输出 `%`  |

## 浮点数

### 浮点数输出精度
```cpp
printf("%.10f\n", ans);
```

### 宽度控制
```cpp
printf("%5d\n", 12);
// 输出宽度至少 5，默认右对齐："   12"

printf("%-5d\n", 12);
// "12   ", 左对齐

printf("%05d\n", 12);
// "00012", 补零
```

## 输出数组
```cpp
for (int i = 1; i <= n; i++) {
    printf("%d%c", a[i], i == n ? '\n' : ' ');
}
```

## 关流

### 解释
```cpp
ios::sync_with_stdio(false);
// 让cin/cout 和scanf/printf 不要同步

cin.tie(nullptr);
// 解除 cin 和 cout 的绑定
```

### 应用

```cpp
// 方式1
ios::sync_with_stdio(false);
cin.tie(nullptr);

cin >> n;
cout << ans << '\n';

// 方式2
scanf("%d", &n);
printf("%d\n", ans);
```



