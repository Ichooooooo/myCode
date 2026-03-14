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

void solve(){   
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    unordered_map<int, int> c;
    ll ans = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i] = a[i] + i;
        c[i - a[i]] ++;
    }
    for (int i = 1; i <= n; i ++) {
        ans += c[b[i]];
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
