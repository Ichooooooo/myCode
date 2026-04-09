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
    vector<int> a(n + 1);
    for (int i  = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> b(n + 1);
    b[1] = a[1];
    ll ans = 1;
    for (int i = 2; i <= n; i ++) {
        ll l = 1, r = ans, mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            if (a[i] >= b[mid]) {
                l = mid + 1;    
            } else {
                r = mid - 1;
            }
        }   
        b[l] = a[i];
        // cout << l << ' ' << b[l] << endl;
        if(l > ans) ans ++;
    }
    cout << ans << endl;
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