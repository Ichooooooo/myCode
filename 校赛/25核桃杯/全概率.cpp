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
const int mod=998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    double ans = 0;
    vector<double> a(n);
    vector<double> b(n);
    for(double & i : a){
        cin >> i;
    }
    for(double & i : b){
        cin >> i;
    }
    for(int i = 0; i < n; i ++){
        ans += a[i] * b[i];
    }
    cout << fixed << setprecision(4) << ans << endl;
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
