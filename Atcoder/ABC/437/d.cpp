#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n + 1);
    vector<ll> b(m + 1);
    for (ll i = 1; i <= n; i ++) cin >> a[i];
    for (ll j = 1; j <= m; j ++) cin >> b[j];
    
    sort(a.begin() + 1, a.end());
    sort(b.begin() + 1, b.end());

    vector<int> pre(m + 1, 0);
    for (int i = 1; i <= m ; i ++) {
        pre[i] = pre[i - 1] + b[i];
    }

    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        int p = upper_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
        ans += (p - 1) * a[i] - pre[p - 1] + (pre[m] - pre[p - 1] - (m - p + 1) * a[i]);
        ans %= mod;
    }
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