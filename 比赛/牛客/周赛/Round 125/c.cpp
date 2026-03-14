#include<bits/stdc++.h>
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
    vector<int> a(n);

    for (int & i : a) cin >> i;
    ll ans = 0, mn = 1e16;
    for (int i = 0; i < n; i ++) {
        if (a[i] != 0) {
            mn = min(mn, a[i]);
        } else {
            if (mn != 1e16) {
                ans += mn;
                mn = 1e16;
            }
        }
    }
    if (mn != 1e16) {
        ans += mn;
    }
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