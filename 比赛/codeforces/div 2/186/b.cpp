#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    ll x, y;
    cin >> x >> y;
    ll a = x, b = y, cn = 1, cnt1 = 0,cnt2 = 0;
    while (a >= 0 && b >= 0) {
        if (cnt1 & 1) {
            b -= cn;
        } else {
            a -= cn;
        }
        cn *= 2;
        cnt1 ++;
        // cout << a << ' '  << b << endl;
    }
    a = x, b = y, cn = 1;
    while (a >= 0 && b >= 0) {
        if (cnt2 & 1) {
            a -= cn;
        } else {
            b -= cn;
        }
        cn *= 2;
        cnt2 ++;
        // cout << a << ' '  << b << endl;
    }
    cout << max(cnt1, cnt2) - 1 << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}