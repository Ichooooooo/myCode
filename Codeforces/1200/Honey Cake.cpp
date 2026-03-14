#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    int w, h, d, n;
    cin >> w >> h >> d >> n;

    int a, b, c;
    
    a = gcd (n, w);
    n /= a;
    b = gcd (h, n);
    n /= b;
    c = gcd (d, n);
    n /= c;
    if (n == 1) {
        cout << a - 1 << ' ' << b - 1 << ' ' << c - 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}