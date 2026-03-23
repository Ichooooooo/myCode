#include<bits/stdc++.h>
#define pi acos(-1)
#define fi first 
#define se second 
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 1e9 + 7;
const double eps = 1e-10;

ll ksm(ll n) {
    ll x = 1, y = 2;
    while (n) {
        if(n & 1) x *= y % mod;
        y *= y % mod;
        n >>= 1;
    } 
    return x;
}

void solve(){   
    int n;
    cin >> n;
    cout << ksm(n / 2) << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}