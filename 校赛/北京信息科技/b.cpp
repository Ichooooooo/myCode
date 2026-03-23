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

ll ksm(int x){
    ll res = 1, y = 2;
    while(x){
        if(x & 1){
            res *= y;
            res %= mod;
        }
        y *= y;
        y %= mod;
        x >>= 1;
    }
    return res;
}

void solve(){   
    int n;
    cin >> n;
    cout << ksm(n - 1) << endl;
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
