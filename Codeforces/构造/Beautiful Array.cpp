
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 1 << '\n';
        cout << a << '\n';
    } else if (a > b) {
        int ch = a - b;
        cout << 3 << '\n';
        cout << b << ' ' << b << ' ' << a + 2 * ch << '\n';
    } else {
        int ch = b - a;
        cout << 3 << '\n';
        cout << b << ' ' << b << ' ' << a - 2 * ch << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}