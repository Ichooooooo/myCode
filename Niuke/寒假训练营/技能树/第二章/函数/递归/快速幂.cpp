#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int a, b, p;
    cin >> a >> b >> p;

    a = a % p;
    auto qpow = [&] () -> int {
        int x = a, y = 1;
        while (b) {
            if (b & 1) y = y * x % p; 
            x = x * x % p;
            b >>= 1;
        }

        return y;
    };

    cout << qpow () << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}