
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, t;
    cin >> n >> t;
    vector <int> h (n), c(n);
    for (int & i : h)  cin >> i;

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        cin >> c[i];
        if (h[i] <= t) ans += c[i];
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}