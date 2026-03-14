
#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int mod = 998244353;
using i128 = __int128_t;

void ovo(){   
    int p, q;  cin >> p >> q;
    
    int x = p / 2, y = q / 3;
    int k = (i128)(3 * y - 2 * x) + q % 3 - p % 2;
    // cout << k << '\n';
    if (k <= min(x, y) && k != 0) {
        cout << "Bob" << '\n';
    } else {
        cout << "Alice" << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}