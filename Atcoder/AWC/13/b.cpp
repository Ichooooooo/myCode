
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, m;
    cin >> n >> m;
    
    set <array<int, 2>> st;
    int u, v;
    while (m --) {
        cin >> u >> v;
        st.insert({u, v});
    }

    int ans = 0;
    for (auto [x, y] : st) {
        if (st.find({y, x}) != st.end()) ans ++;
    }

    cout << ans / 2 << '\n';


}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}