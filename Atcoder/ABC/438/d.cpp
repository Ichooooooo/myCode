#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    vector<ll> pa(n, 0), pb(n, 0), pc(n, 0);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if(i != 0) pa[i] += pa[i - 1];
        pa[i] += a[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> b[i];
        if(i != 0) pb[i] += pb[i - 1];
        pb[i] += b[i];
    }
    for (int i = 0; i < n; i ++) {
        cin >> c[i];
        if(i != 0) pc[i] += pc[i - 1];
        pc[i] += c[i];
    }

    ll amx = -1e7, ans = -1e7, cur = 0;
    for (int i = 1; i < n - 1; i ++) {
        amx = max(amx, pa[i - 1] - pb[i - 1]);
        cur = pc[n - 1] + amx + (pb[i] - pc[i]);
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}