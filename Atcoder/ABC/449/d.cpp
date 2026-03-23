
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int l, r, d, u;
    cin >> l >> r >> d >> u;

    int ans = 0;
    for (int i = l; i <= r; i ++) {
        if (i % 2 == 0) {
            int ll = max (-abs(i), d);
            int rr = min (abs(i), u);
            if (ll <= rr)
            ans += rr - ll + 1;
        }
    }

    for (int i = d; i <= u; i++) {
        if (i % 2 == 0) {
            int ll = max (l, -abs(i) + 1);
            int rr = min (r, abs(i) - 1);
            if (ll <= rr) 
            ans += (rr - ll) + 1;
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}