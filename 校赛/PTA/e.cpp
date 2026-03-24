#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    string a, b;
    cin >> a >> b;
    double aa = stod(a), bb = stod(b);
    // cout << aa << bb << endl;
    int pa, pb;
    if (a.find('.') != string :: npos) {
        pa = a.find('.');
    } else {
        cout << b << ' ' << b << endl;
        return;
    }
    if (b.find('.') != string :: npos) {
        pb = b.find('.');
    } else {
        cout << a << ' ' << a << endl;
        return;
    }
    string sa = a.substr(pa + 1);
    string sb = b.substr(pb + 1);
    // cout << pa << pb << endl;
    int c = stoll(sa), d = stoll(sb);
    if(c > d) {
        cout << a << ' ';
    } else {
        cout << b << ' ';
    }
    cout << ((aa > bb) ? a : b) << endl;
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