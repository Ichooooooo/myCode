# C++ 字符串速查（极简示例版）

---

## 1) `cin >>` 后接 `getline`

```cpp
int n; 
cin >> n;
cin.ignore();
string line;
getline(cin, line); // 读一整行（可为空）
```

## 2) 基础
```cpp
string s = "hello";
s.push_back('!');      // 追加字符
s.pop_back();          // 删除末尾字符
s += " world";         // 追加字符串
s.assign("new");       // 重新赋值
int n = (int)s.size(); // 长度
```

## 3) 查找 find / rfind
```cpp
string s = "a/b/c";
size_t p1 = s.find('/');      // 第一次出现
size_t p2 = s.rfind('/');     // 最后一次出现
if (s.find("b/") != string::npos) { /* 存在子串 */ }

string s = "abcabcabc";
int pos = s.find("abc", 3);   // 从某个位置开始找
```

## 4) 截取 substr
```cpp
string s = "abcdefg";
cout << s.substr(3) << "\n";     // defg：从 pos 到末尾
cout << s.substr(2, 3) << "\n";  // cde：从 pos 开始取 len 个
```

## 5) 替换

5.1 s.replace(pos, cnt, str);
```cpp
string s = "abcdef";
s.replace(1, 3, "xyz"); // bcd -> xyz
// s == "axyzef"
// 把 s[pos ... pos+cnt-1] 替换成 str
```

5.2 s.replace(pos, cnt, num, ch);
```cpp
string s = "abcdef";
s.replace(2, 3, 4, 'x');
// abxxxxf
// 把一段替换成 num 个 ch
```

5.2 std::replace（替换单个字符）
```cpp
string s = "12,34,56";
replace(s.begin(), s.end(), ',', ' '); // 逗号变空格
// s == "12 34 56"
```

## 6) 字符串 ↔ 数字
```cpp
6.1 字符串 -> 数字 stoi / stoll

6.2 数字 -> 字符串 to_string
```