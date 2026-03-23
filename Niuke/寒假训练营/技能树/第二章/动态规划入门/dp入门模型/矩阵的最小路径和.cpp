#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m;  cin >> n >> m;

    vector <vector <int>> a (n + 1, vector <int> (m + 1));

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    // vector <vector <int>> a (n + 1, vector <int> (m + 1));

    // wa 点 : 内存超限, 用a更新值就好, 不单独开

    // a[1][1] = a[1][1];
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (i == 1) {
                if (j == 1) continue;
                a[i][j] = a[i][j - 1] + a[i][j];
            } else {
                if (j == 1) a[i][j] = a[i - 1][j] + a[i][j];
                else {
                    a[i][j] = min (a[i - 1][j], a[i][j - 1]) + a[i][j];
                }
            }
        }
    }

    cout << a[n][m] << endl;
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