#include<bits/stdc++.h>
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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    ll d1 , d2, d3;
    d1 = pow(a - c, 2) + pow(b - d, 2);
    d2 = pow(a - e, 2) + pow(b - f, 2);
    d3 = pow(e - c, 2) + pow(f - d, 2);
    if(d1 == d2 && d2 == d3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}