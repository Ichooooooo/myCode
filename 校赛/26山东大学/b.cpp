
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    string s; cin >> s;
    
    int cw = 0, co = 0, cf = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'w') cw ++;
        else if (s[i] == 'o') co ++;
        else cf++;
    }

    cout << cf - cw << ' ' << cw - (cf - cw) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}