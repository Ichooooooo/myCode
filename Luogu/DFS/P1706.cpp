#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    vector<int>a (n + 1);
    vector<bool> vis (n + 1, true);

    auto dfs = [&] (int dep, auto self) -> void{
        if (dep > n) {
            for (int i = 1; i <= n; i ++) {
                printf("%5lld", a[i]);
            }
            printf("\n");
            return;
        }
        for (int i = 1; i <= n; i ++) {
            if (vis[i]) {
                a[dep] = i; 
                vis[i] = 0;
                self(dep + 1, self);
                vis[i] = 1;
            } 
        }
    };

    dfs(1, dfs);
}

//求从n个数里选取m个数的组合情况
void solve2() {
    int n, m;
    cin >> n >> m;
    vector<int>a (m + 1);
    vector<bool> vis (n + 1, true);

    auto dfs = [&] (int dep, auto self) -> void{
        if (dep > m) {
            for (int i = 1; i <= m; i ++) {
                printf("%5lld", a[i]);
            }
            printf("\n");
            return;
        }
        for (int i = 1; i <= n; i ++) {
            if (vis[i] && (dep == 1 || i > a[dep - 1])) {
                a[dep] = i; 
                vis[i] = 0;
                self(dep + 1, self);
                vis[i] = 1;
            } 
        }
    };

    dfs(1, dfs);
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}