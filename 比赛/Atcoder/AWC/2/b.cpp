#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m, k; cin >> n >> m >> k;
    vector <int> a (n), vis (n, 1);
    for (int & i : a) cin >> i;
    int t;  while (m --) {cin >> t; vis[t - 1] = 0; }

    int cnt = 0, ans = 0;
    for (int i = 0; i < n; i ++) {
        if (!vis[i] && a[i] < k) {
            cnt ++; ans += a[i];
        }
    }

    cout << cnt << ' ' << ans << '\n';
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