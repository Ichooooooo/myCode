#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
const int N = 15;

void solve(){   
    int n;
    cin >> n;
    char a[15][15];
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) 
            cin >> a[i][j];
    }
    int c[N], djz[2 * N], djc[2 * N] ;
    for (int i = 1; i <= n; i ++) c[i] = 1;
    for (int i = 1; i <= 2 * n; i ++) djz[i] = 1;
    for (int i = 1; i <= 2 * n; i ++) djc[i] = 1;

    ll ans = 0;
    auto dfs = [&] (int dep, auto self) -> void {
        if (dep > n) {
            ans ++;
            return;
        }
        int i = dep;
        for (int j = 1; j <= n; j ++) {
            if (a[i][j] == '*' & c[j] & djz[i - j + n] & djc[i + j]) {
                c[j] = 0; djz[i - j + n] = 0; djc[i + j] = 0;
                self(dep + 1, self);
                c[j] = 1; djz[i - j + n] = 1; djc[i + j] = 1;
            }
        }
        //没有满足的时候自动 return（void 函数）
    };

    dfs(1, dfs);

    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}