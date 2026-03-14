#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;  cin >> n;
    vector <vector <int>> a (n + 1, vector <int> (n + 1));
    int m = n * n - 1; a[0][(n - 1) / 2] = 1;

    int r = 0, c = (n - 1) / 2, k = 1, x, y;
    while (m --) {
        // cout << m << ' ';
        k ++;
        if (! a[(r - 1 + n - 1) % n + 1][(c + 1) % n]) {
            x = (r - 1 + n - 1) % n + 1; y = (c + 1) % n;
            a[x][y] = k;
            r = x;
            c = y;
        } else {
            x = (r + 1 + n - 1) % n + 1; y = c;
            a[x][y] = k;
            r = x; 
            c = y;
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
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