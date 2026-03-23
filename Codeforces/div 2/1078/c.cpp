
// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// const int mod = 998244353;

// void ovo() {
//     int n, k; cin >> n >> k;
//     vector <vector<int>> vis (n, vector<int> (26));
//     vector <string> ss (n);
//     for (string & s : ss) cin >> s;

//     for (int i = 0; i < n; i ++) {
//         for (int j = 0; j < k; j ++) {
//             vis[i][ss[i][j] - 'a'] ++;
//         }
//     }

//     vector <int> yz; int fj = n;
//     for (int i = 1; i * i <= fj; i ++) {
//         if (fj % i == 0) 
//     }
//     // string ans;
//     // for (int i = 0; i < yz.size(); i ++) { // 枚举长度
//     //     string t;
//     //     int tar = yz[i];

//     //     int okkk = 1;
//     //     for (int j = 0; j < tar; j ++) {  // 枚举长度的每一位
//     //         int okk = 0;
//     //         for (int p = 0; p < 26; p ++) { // 改填什么字母
//     //             int ok = 1;
//     //             for (int k = j; k < n; k += tar) { // 判断合理性
//     //                 if (!vis[k][p]) {ok = 0; break;}
//     //             }
//     //             if (ok) {
//     //                 char tt = p + 'a';
//     //                 t += tt;
//     //                 okk = 1;
//     //                 break;
//     //             }
//     //         }
//     //         if (!okk) {
//     //             okkk = 0;
//     //         }
//     //     }

//     //     if (!okkk) continue;
//     //     else {
//     //         ans = t;
//     //         break;
//     //     }
//     // } 

//     // for (int i = 0; i < n / ans.size(); i ++) cout << ans;
//     // cout << '\n';
// }
 
// signed main() {
//     ios::sync_with_stdio(false); cin.tie(0);
//     int _=1;
//     cin>>_;

//     while (_--) ovo();
// }