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
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    int ok = 0;
    if(a[1] < x){
        cout << "No" << endl;
        return;
    }
    a[1] -= x;
    for(int i = 2; i <= n; i ++){
        if(a[i] + a[i - 1] < x){
            ok = 1;
            break;
        }else{
            a[i] -= max(x - a[i - 1], 0LL);
        }
    }
    if(ok){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
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
