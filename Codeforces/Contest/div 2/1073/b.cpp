
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    int cn0 = 0, cn1 = 0;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        if (x == 0) cn0++;
        if (x == 1) cn1++;
    }    
    
    if ((cn0 == 1) || (cn0 > 1 && cn1 > 0)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}