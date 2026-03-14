#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> pz(n), pf(n), pre(n);

    for (ll i = 0; i < n; i ++) {
        cin >> a[i];
        if (i == 0) {
            pre[i] = a[i];
            pz[i] = a[i];
            pf[i] = 0;
        } else {
            pre[i] = pre[i - 1] + a[i];
            pz[i] = pz[i - 1]; pf[i] = pf[i - 1];
            if(a[i] > 0) pz[i] += a[i];
            else pf[i] += a[i];
        }
    }

    // cout << pz[0] << ' ' << ' ' << pf[0] << ' ' << pre[0] << ' ' << pre[1] << endl;
    ll cur, ans = -1e16;
    for (int i = 0; i < n; i ++) {
        if (i > 0) cur = pz[i - 1] - pf[i - 1] - (pre[n - 1] - pre[i]);
        else cur = -1 * (pre[n - 1] - pre[i]);
        // cout << i << ' ' <<  pz[i - 1] - pf[i - 1] << ' ' << (pre[n - 1] - pre[i]) << ' ' << cur << endl;
        ans = max(ans, cur);
    }
    cout << ans << endl;
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