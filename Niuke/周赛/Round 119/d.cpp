#include<bits/stdc++.h>
#define int long long 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod=998244353;
const double eps = 1e-10;

ll ksm(int x, int y) {
    int res = 1;
    while(y) {
        if(y & 1) {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return ksm(x, mod - 2);
}

void solve(){   
    int n, k;
    cin >> n >> k;
    ll sum = 0, t, mn = 0;
    for(int i = 0; i < n; i ++) {
        cin >> t;
        if((i + 1) & 1) {
            sum += t;
        }else {
            sum -= t;
        }
        mn = min(mn, sum);
    }
    // cout << mn << ' ';
    if(mn < 0) {
        mn *= -1;
        if(mn > 60) {
            cout << 0 << endl;
            return;
        }
        k >>= mn;
        if(k == 0) {
            cout << 0 << endl;
            return;
        }
        k <<= mn;
    }
    // cout << k << ' ';
    if(sum >= 0) {
        cout << (k % mod * ksm(2LL, sum)) % mod << endl;
    }else {
        cout << (k % mod * inv(ksm(2LL, abs(sum)))) % mod << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
