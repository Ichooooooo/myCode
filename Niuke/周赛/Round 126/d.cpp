#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int x, y, n;
    cin >> x >> y >> n;
    vector<int> a(x + 1), b (y + 1), c(n + 1);
    for (int i = 1; i <= x; i ++) cin >> a[i];
    for (int i = 1; i <= y; i ++) cin >> b[i];
    if (a[x] != b[y] || (x + y - 1) > n) {
        cout << -1 << endl;
    } else {
        int res = n - (x + y - 1), mx = a[x];
        for (int i = 1; i <= x; i ++) {
            cout << a[i] << ' ';
        }
        while (res --) {
            cout << mx << ' ' ;
        }
        for (int i = y - 1; i >= 1; i --) {
            cout << b[i] << ' ';
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