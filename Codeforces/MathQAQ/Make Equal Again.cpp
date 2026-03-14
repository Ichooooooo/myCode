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
    vector<int> a(n);
    for(int & i : a){
        cin >> i;
    }
    int a1 = 1, a2 = 1;
    for(int i = 1; i < n; i ++){
        if(a[i] == a[0]){
            a1 ++;
        }else{
            break;
        }
    }
    for(int i = n - 2; i >= 0; i --){
        if(a[i] == a[n - 1]){
            a2 ++;
        }else{
            break;
        }
    }
    // cout << a[0] << " " << a[n - 1] << endl;
    if(a1 + a2 > n){
        cout << 0 << endl;
    }else if(a[0] != a[n - 1]) {
        cout << n - max(a1, a2) << endl;
    }else {
        cout << n - (a1 + a2) << endl;
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
