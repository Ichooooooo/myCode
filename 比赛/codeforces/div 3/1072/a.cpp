#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    if (n % 2  == 0 && n != 2) {
        cout << 0 << endl;
    } else if (n == 2) {
        cout << 2 << endl;
    } else if (n == 3) {
        cout << 3 << endl;
    } else {
        cout << 1 << endl;
    }
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