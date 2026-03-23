#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    string s;
    cin >> s;
    if(s == "ABD") {
        cout << 4 << endl;
    } else if (s == "AB" || s == "AD" || s == "BD" || s == "A" || s == "B" || s == "D") {
        cout << 2 << endl;
    } else {
        cout << 0 << endl;
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