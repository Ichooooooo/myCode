#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
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
    vector<int> a(n + 1, 0);
    int b, c;
    for(int i = 0; i < n - 1; i ++) {
        cin >> b >> c;
        a[b] ++;
        a[c] ++;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (a[i] < 2) {
            ans ++;
        } 
    }
    cout << ans / 2 + ans % 2 << endl;
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