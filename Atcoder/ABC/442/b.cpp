#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int q;  cin >> q;
    int t, cur = 0, ok = 0;
    while (q --) {
        cin >> t;
        if (t == 1) {
            cur ++;
        } else if (t == 2) {
            cur = max (0LL, cur - 1);
        } else {
            ok ^= 1;
        }
        if (ok && cur >= 3) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
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