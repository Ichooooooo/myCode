
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, p;
    cin >> n >> p;

    vector <int> a (n + 1), pre (n + 1);
    unordered_map <int, int> mp;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = (pre[i - 1] + a[i]) % p;
        if (mp.find(pre[i]) == mp.end())
        mp[pre[i]] = i;
    }

    set <int> st;

    int mx = -1, ll, rr;
    for (int i = 1; i <= n; i ++) {
        auto fd = st.upper_bound(pre[i]);
        if (fd == st.end()) {
            if (mx < pre[i]) {
                mx = pre[i];
                ll = 1; 
                rr = i;
            } 
        } else {
            int cur = (pre[i] - *fd + p) % p;
            if (cur > mx) {
                mx = cur;
                ll = mp[*fd] + 1;
                rr = i;
            }
        }
        
        st.insert(pre[i]);
    }

    cout << ll - 1 << ' ' << rr - 1 << ' ' << mx << '\n';

    
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