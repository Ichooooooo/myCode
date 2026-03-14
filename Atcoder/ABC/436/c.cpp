#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m; cin >> n >> m;
    set <PII> st;

    int r, c, cnt = 0;
    while (m --) {
        cin >> r >> c;
        bool ok = true;
        for (int idx = -1; idx <= 1; idx ++) {
            for (int idy = -1; idy <= 1; idy ++) {
                if (st.find ({r + idx, c + idy}) != st.end()) {
                    ok = false;
                }
            }
        }
        if (ok) st.insert({r, c});
    }

    cout << cnt << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}