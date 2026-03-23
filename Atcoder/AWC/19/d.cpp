
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m, t;
    cin >> n >> m >> t;

    vector <array <int, 2>> a;
    a.reserve(n);
    int x, y, z;
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        cin >> x >> y >> z;
        if (y >= t) ans += x;
        else a.push_back({x, z});
    }

    int as = a.size();
    if (as == 0) {
        cout << ans << '\n';
        return;
    }

    vector <int> dp (m + 1);
    for (auto [x, y] : a) {
        for (int i = m; i >= y; i --) {
            dp[i] = max (dp[i], dp[i - y] + x);
        }
    }

    cout << ans + dp[m] << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}