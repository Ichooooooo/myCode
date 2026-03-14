#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m; cin >> n >> m;
    vector <pair <int, int>> p (n);
    for (int i = 0; i < n; i ++) {
        cin >> p[i].first >> p[i].second;
    }
    int ans = -1;
    for (auto [a, b] : p) ans = max (ans, (m - a + b - 1) / b);

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}