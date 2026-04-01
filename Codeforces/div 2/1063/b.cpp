
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> p (n + 1);

    int mnp, mxp;
    for (int i = 1; i<= n; i ++) {
        cin >> p[i];
        if (p[i] == 1) mnp = i;
        if (p[i] == n) mxp = i;
    }

    string s; cin >> s;

    if (s[0] == '1' || s[n - 1] == '1' || s[mnp - 1] == '1' || s[mxp - 1] == '1') {
        cout << -1 << '\n';
    } else {
        cout << 5 << '\n';
        cout << 1 << ' ' << mnp << '\n';
        cout << 1 << ' ' << mxp << '\n';
        cout << mnp << ' ' << n << '\n';
        cout << mxp << ' ' << n << '\n';
        cout << min (mnp, mxp) << ' ' << max (mnp, mxp) << '\n';
    }
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}