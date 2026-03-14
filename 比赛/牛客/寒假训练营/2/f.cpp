#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){    
    // auto check = [](int x) -> void {
    //     int p, q, y = LLONG_MAX;
    //     for (int i = 1; i <= 1000; i ++) {
    //         for (int j = i + 1; j <= 1001; j ++) {
    //             int a = i * x, b = j * x;
    //             if (y > (a ^ b)) {
    //                 y = (a ^ b);
    //                 p = i, q = j;
    //             }
    //         }
    //     }
    //     int a = x * p, b = x * q;
    //     for (int bit = 10; bit >= 0; bit --) {
    //         if (x & (1 << bit)) cout << 1;
    //         else cout << 0;
    //     }
    //     cout << endl;
    //     for (int bit = 10; bit >= 0; bit --) {
    //         if (a & (1 << bit)) cout << 1;
    //         else cout << 0;
    //     }
    //     cout << endl;
    //     for (int bit = 10; bit >= 0; bit --) {
    //         if (b & (1 << bit)) cout << 1;
    //         else cout << 0;
    //     }
    //     cout << endl;
    //     cout << x << ' ' <<  p << ' ' << q << ' ' << (( x*p) ^ (x * q)) << endl;
    //     if (x % 4 == 3) cout << endl;
    // };
    // for (int n = 0; n <= 100; n ++) {
    //     check (n);
    // }

    int n;  cin >> n;
    int a, b;
    int t = n, bit = 0;
    while (t) {
        t >>= 1;
        bit ++;
    }

    a = (n << bit); b = a + n;
    cout << a << ' ' << b << endl;
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