#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int a, b, op, c, d;
    cin >> a >> b >> op >> c >> d;
    if (b == 0 || d == 0) {
        cout << "inf" << endl;
        return;
    }
    int fz, fm;
    if (op == 1) {
        fz = a * d + c * b;
        fm = b * d;
    } else if (op == 2) {
        fz = a * d - c * b;
        fm = b * d;
    } else if (op == 3) {
        fz = a * c;
        fm = b * d;
    }  else {
        if (c == 0) {
            cout << "inf" << endl;
            return;
        }
        fz = a * d;
        fm = c * b;
    }
    int yz = gcd (fz, fm);
    fz /= yz; fm /= yz;
    if (fm < 0) {
        fz *= -1; fm *= -1;
    }

    cout << fz <<  ' ' << fm << endl;
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