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
    int n;
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, t;
    unordered_map<int, int> mp;
    for(int i = 0; i < 2 * n; i ++){
        cin >> t;
        mp[t] ++;
    }
    for(auto &[a, b]: mp) {
        if(b == 1) {
            c1 ++;
        }else if(b & 1) {
            c2 ++;
        }else if(b % 4 == 2){
            c3 ++;
        }else {
            c4 ++;
        }
    }
    ll ans = 0;
    // cout << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4 << endl;
    if(c1 == 0 && c2 == 0 && c4 & 1) {
        ans = 2 * c3 + (c4 - 1) * 2;
    }else {
        ans = 2 * c3;
        ans = ans + c1 + c2 + 2 * c4;
    }
    cout << ans << endl;
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
