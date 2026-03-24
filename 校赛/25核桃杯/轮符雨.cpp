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
    vector<PII> a(n);
    vector<int> b(n);
    for(int i = 0; i < n; i ++){
        cin >> a[i].fi;
        b[i] = a[i].fi;
        a[i].se = i;
    }
    sort(a.rbegin(), a.rend());
    if(a[0].se == 0){
        cout << a[0].fi - a[n - 1].fi << endl;
    }else if(a[n - 1].se == n - 1){
        cout << a[0].fi - a[n - 1].fi << endl;
    }else {
    cout << max(max(a[0].fi - b[n - 1], b[0] - a[n - 1].fi), b[n - 1] - b[0]) << endl;
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
