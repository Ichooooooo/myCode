
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int x, y;
    cin >> x >> y;

    if (x + y > 0 || (x + y) % 3 == 0) {
        if (y > 0) {
            if (2 * y <= x && (x - 2 * y) % 3 == 0) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        } else {
            y *= -1;
            if (4 * y <= x && (x - 4 * y) % 3 == 0) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        }
    } else {
        cout << "No" << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}