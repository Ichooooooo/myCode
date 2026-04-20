
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int t; cin >> t;
    auto cal = [] (int t) -> int {
        return t * t + 2 * t + 3;
    };

    cout << cal (cal (cal (t) + t) + cal (cal (t))) << '\n';  
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}