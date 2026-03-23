#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int a, b, c;
    cin >> a >> b >> c;
    int x;
    cin >> x;
    cout << x << endl;
    if (x >= a) {
        cout << "yi deng jiang" << endl;
    } else if (x >= b) {
        cout << "er deng jiang" << endl;
    } else if(x >= c) {
        cout << "san deng jiang" << endl;
    } else {
        cout << "mei jiang T_T" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}