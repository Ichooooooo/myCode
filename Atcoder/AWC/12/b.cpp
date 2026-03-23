
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, t, c, d;
    cin >> n >> t >> c >> d;

    int ans = 0; int x;
    for (int i = 0; i < n; i ++) {
        cin >> x;
        if (x >= t) ans += min (c, d);
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}