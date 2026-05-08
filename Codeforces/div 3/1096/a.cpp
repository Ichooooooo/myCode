
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int x, y; 
    cin >> x >> y;
    if ((x & 1) && (y & 1)) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}