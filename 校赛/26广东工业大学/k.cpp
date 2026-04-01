
// #include <bits/stdc++.h>
// // #define int long long
// using namespace std;
// const int mod = 998244353;

// void ovo() {
//     int n; cin >> n;
//     vector <vector <pair<char, int> > > e(n + 1);
//     for (int i = 2; i <= n; i++) {
//         int v;
//         char c;
//         cin >> v >> c;
//         e[v].push_back({c, i});
//     }

//     for (int i = 1; i <= n; i++) {
//         sort(e[i].begin(), e[i].end());
//     }
//     vector <int> ans;
//     vector <int> vis(n + 1, 0);
//     auto dfs = [&] (auto self, vector <int> cur) -> void {
//         sort(cur.begin(), cur.end());
//         for( )

//         vector <vector<int> > x(26 + 1);
//         for (auto [c, v] : e[u]) {
//             x[c - 'a'].push_back(v);
//         }
            
//         map <int, int> mp;
//         for (int i = 0; i < 26; i++) {
//             if (x[i].size() >= 2) {
//                 for (int j = 0; j < x[i].size(); j++) {
//                     if (j == 0) continue;
//                     for (auto [c, v] : e[x[i][j]]) {
//                         e[x[i][0]].push_back({c, v});
//                     }
//                     mp[x[i][j]] = true;
//                 }
//             }
//         }
        
//         for (auto [c, v] : e[u]) {
//             if (vis[v]) continue;
//             if (mp[v]) continue;
//             self(self, v);
//         }
        
//     };
//     dfs(dfs, vector <int>{1});

//     for (auto x : ans) {
//         cout << x << ' ';
//     }
//     cout << '\n';
// }

// signed main() {
//     ios::sync_with_stdio(false); cin.tie(0);
//     int _=1;
//     cin>>_;

//     while (_--) ovo();
// }