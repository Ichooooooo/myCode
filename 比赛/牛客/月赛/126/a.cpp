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
    string a, b;
    cin >> a >> b;
    string c, d;
    bool ok = 0;
    if(a.find('+') != string :: npos) {
        c = a.substr(0, '+');
        ok = 1;
    }else {
        c = a;
    }
    if(b.find('+') != string :: npos) {
        d = b.substr(0, '+');
    }else {
        d = b;
    }
    ll e = stoll(c), f = stoll(d);
    if((e > f) || (e == f && ok)) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int _=1;
    cin>>_;
    while(_--){
        solve();
    }
    return 0;
}