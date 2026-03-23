#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, k;
    cin >> n >> k;
    if ((n - k) & 1) {
        cout << -1 << endl;
    } else {
        int i = 1, cn1 = (n - k) / 2;
        for (int j = 1; j <= cn1; j ++, i ++) {
            cout << j << ' ' << j << ' ';
        } 
        for (int j = 1; j <= k; j ++, i ++) {
            cout << i << ' ';
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