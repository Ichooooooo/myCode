#include<bits/stdc++.h>
#define int long long 
#define endl '\n' 
#define INF 0x3f3f3f3f3f3f3f3f
#define pi acos(-1)
#define fi first 
#define se second 
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

ll zhs(int x) {
    if(x == 1) {
        return 0;
    }else {
        return (x * (x - 1)) / 2;
    }
}

void solve(){   
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(i == 0) {
            b[i] = a[i];
        }else {
            b[i] = b[i - 1] ^ a[i];
        }
        // cout << b[i] << endl;
        mp[b[i]] ++;
    }
    ll ans = 0;
    for(auto &[x, y] : mp) {
        if(x == 0) ans += y;
        // cout << x << ' ' << y <<  endl;
        ans += zhs(y);
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n=1;
    // cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
