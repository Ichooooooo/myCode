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
    vector<array<ll, 2>> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort (a.begin() + 1, a.end(), [](auto x, auto y) {
        if (x[0] != y[0]) return x[0] < y[0];
        else return x[1] < y[1];
    });

    ll l = a[1][0], r = a[1][1], ans = 0;
    for (int i = 2; i <= n; i ++) {
        if (a[i][0] <= r) {
            r = max (a[i][1], r);
        } else {
            ans += (r - l + 1);
            l = a[i][0];
            r = a[i][1];
        }
        // cout << ans << ' ';
    }

    ans += (r - l + 1);
    
    cout << ans << endl;
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