
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
using i128 = __int128_t;
void ovo(){   
    int g, m, d, k, v;
    cin >> g >> m >> d >> k >> v;

    if (g <= i128(d * k) && k != 0) {
        if ((i128(m - g) * d) >= i128(g * v)) {
            cout << "Yes"<< '\n';
        } else {
            cout << "No" << '\n';
        }
    } else {
        int s1 = g - d * k;
        int s2 = m - g - k * v;
        if (i128(s1 * v) <= s2) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}