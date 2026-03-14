
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, t; cin >> n >> t;
    int ans = 0; int p, q;
    for (int i = 0; i < n; i ++) {
        cin >> p >> q;
        ans += max (0LL, p - q * t);
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}