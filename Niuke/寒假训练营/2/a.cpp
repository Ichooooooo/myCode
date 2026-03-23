#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int a, b, c;
    cin >> a >> b >> c;
    int mx = max (a, max (b, c));
    
    if ((b == mx || b == (mx - 1)) && (c == mx || c == mx - 1) && (a == mx || a == mx - 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}