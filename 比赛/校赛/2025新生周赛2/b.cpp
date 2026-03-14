// #include<bits/stdc++.h>
// #define int long long 
// #define INF 0x3f3f3f3f3f3f3f3f
// #define pi acos(-1)
// #define fi first 
// #define se second 
// using ll = long long;
// using namespace std;
// typedef pair<int,int> PII;
// typedef pair<int,PII> PIII;
// const int mod=998244353;
// const double eps = 1e-10;

// void solve(){   
//     int n, m;
//     cin >> n >> m;
//     vector<vector<char>> a(n, vector<char>(n));
//     vector<vector<char>> b(m, vector<char>(m));
//     for(int i = 0; i < n; i ++) {
//         for(int j = 0; j < n; j ++){
//             cin >> a[i][j];
//         }
//     }
//     int p = 0, q = 0;
//     for(int i = 0; i < n; i ++) {
//         if(i % m != 0) {
//             continue;
//         }
//         for(int j = 0; j < n; j ++){
//             if(j % m != 0){
//                 continue;
//             }
//             b[p][q] = a[i][j];
//             q ++;
//         }
//         p ++;
//     }
//     for(int i = 0; i < m; i ++){
//         for(int j = 0; j < m; j ++){
//             cout << b[i][j];
//         }
//         cout << endl;
//     }
// }

// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0),cout.tie(0);
//     int n=1;
//     cin>>n;
//     while(n--){
//         solve();
//     }
//     return 0;
// }


#include<bits/stdc++.h>
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod=998244353;
const double eps = 1e-10;

void solve(){   
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(n));
    for(auto & i : a){
        for(char & j : i){
            cin >> j;
        }
    }
    for(int i = 0; i < n; i += m){
        for(int j = 0; j < n; j += m){
            cout << a[i][j];
        }
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
