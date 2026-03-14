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

void solve(){   
    int n, x, k;
    cin >> n >> x;
    ll ans = 0;
    for(int i = 1; i <= min(n, x); i ++){
        for(int j = 1; i * j <= n && i + j < x; j ++){
            k = min((n - i * j) / (i + j), x - i - j);
            ans += k;
        }
    }
    cout << ans << '\n';
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
