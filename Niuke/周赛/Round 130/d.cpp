#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void ovo(){   
    // for (int i = 1; i <= 15; i ++) {
    //     for (int j = i + 1; j <= 16; j ++) {
    //         cout << i << ' ' << j  << ' ' << (double)(1.0 * i / j) << endl;
    //     }
    // }

    int a, b;  cin >> a >> b;
    
    if (b == 0 && a == 1) {
        cout << 1 << ' ' << 20 << '\n';
    } else if (b == 0 && a > 1) {
        cout << 1 << ' ' << 2 << '\n';
    } else if (b <= 8) {
        if (b == 6) 
        cout << 2 << ' ' << 3 << '\n';
        else if (b == 3)
        cout << 1 << ' ' << 3 << '\n';
        else 
        cout << b << ' ' << 9 << '\n';
    } else {
        if (a & 1) {
            cout << 10 << ' ' << 11 << '\n';
        } else {
            cout << 1 << ' ' << 11 << '\n';
        } 
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