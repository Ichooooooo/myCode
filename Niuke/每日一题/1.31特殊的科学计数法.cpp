#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    string s;  cin >> s;
    int a, b, c;
    a = s[0] - '0', b = s[1] - '0';
    if (s[2] >= '5') b ++;
    if (b >= 10)  {
        a += b / 10;
        b %= 10;
    }

    if (a > 9) {
        c = s.size();
        int t = b;
        b = a % 10, a = a / 10;
        if (t > 5) b ++;
        if (b >= 10)  {
        a += b / 10;
        b %= 10;
        }
    } else {
        c = s.size() - 1;
    }

    cout << a << "." << b << "*" << 10 << "^" << c << endl;
    
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