#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, x;  cin >> n >> x;
    int fr = 0, a, b, c, mx = LLONG_MIN;

    while (n --) {
        cin >> a >> b >> c;
        fr += a * max (b - 1, 0LL);
        mx = max (mx, a * b - c);
    }

    if (fr >= x) {
        cout << 0 << endl;
    } else if (mx <= 0) {
        cout << -1 << endl;
    } else {
        cout << (x - fr + mx - 1) / mx << endl;
    }
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