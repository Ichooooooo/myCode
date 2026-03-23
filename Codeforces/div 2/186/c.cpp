#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){  
    int n;  cin >> n;
    vector <int> a (n + 1), b (n + 1), c (n + 1);

    for (int i = 0; i < n; i ++)  cin >> a[i];
    for (int i = 0; i < n; i ++)  cin >> b[i];
    for (int i = 0; i < n; i ++)  cin >> c[i];

    int x = 0, y = 0, ans;
    for (int i = 0; i < n; i ++) {
        int ok1 = 1, ok2 = 1;
        for (int j = 0; j < n; j ++) {
            if (a[(j + i) % n] >= b[j]) ok1 = 0;
            if (c[(j + i) % n] <= b[j]) ok2 = 0;
        }
        if (ok1) x ++;
        if (ok2) y ++;
    }

    ans = n * x * y;
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}