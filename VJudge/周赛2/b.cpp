#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int a, b, c = 0;
    cin >> a >> b;

    if (a == 1 && b == 1) {
        cout << 0 << '\n';
        return;
    }
    
    while (a > 0 && b > 0) {
        c++;
        if (a >= b) {
            a -= 2; 
            b += 1;
        } else {
            b -= 2;
            a += 1;
        }
    }

    cout << c << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}