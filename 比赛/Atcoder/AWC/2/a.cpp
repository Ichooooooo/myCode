#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k; cin >> n >> k;
    map <int, int> mp;

    int t;
    for (int i = 1; i <= n; i ++) {
        cin >> t;
        if (mp.find (t) == mp.end()) mp[t] = i;
    }

    if (mp.find (k) == mp.end()) {
        cout << -1 << '\n';
    } else {
        cout << mp[k] << '\n';
    }
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