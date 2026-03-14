# string

## 截取 substr
```cpp
string s = "abcdefg";
cout << s.substr(3) << "\n";     // defg：从 pos 到末尾
cout << s.substr(2, 3) << "\n";  // cde：从 pos 开始取 len 个, 如果超出则直接截至结尾
```

## 字符串 ↔ 数字
```cpp
字符串 -> 数字 stoll

数字 -> 字符串 to_string
```