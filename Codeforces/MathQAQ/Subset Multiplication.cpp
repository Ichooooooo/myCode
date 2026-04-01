
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >>n;
    int mn = 0;

    vector <int> a (n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        mn = gcd(mn, a[i]);
    }

    for (int i = 0; i < n; i ++) {
        cout << a[i] / mn << ' ';
    }
    cout << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}