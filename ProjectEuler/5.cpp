
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    set <int> st;
    map <int, int> mp;
    
    st.insert(1);
    for (int i = 2; i <= 20; i ++) {
        int t = i;
        for (int j = 2; j * j <= i; j ++) {
            
            int c = 0;
            while (t % j == 0) {
                t /= j;
                c++;
            }
            if (c) {
                st.insert (j);
                mp[j] = max (mp[j], c);
            }
        }

        if (t > 1) {
            st.insert (t);
            mp[t] = max (mp[t], 1LL);
        }
    }

    int ans = 1;
    for (int x : st) {
        ans *= pow (x, mp[x]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}