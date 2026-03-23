
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, q;
    cin >> n >> q;
    vector <int> a (n + 1);
    set <int> st;
    int sum = 0;
    
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        st.insert(i);
        sum ^= a[i];
    }

    int o, l, r;
    while (q --) {
        cin >> o;
        if (o == 1) {
            cin >> l >> r;
            for (auto it = st.lower_bound(l); it != st.end() && *it <= r; ) {
                int p = *it;
                auto nxt = next(it);

                sum ^= a[p];
                a[p] = a[p] / (p - l + 1);
                sum ^= a[p];
                if (a[p] == 0) st.erase(it);

                it = nxt;
            } 
        } else {
            cout << sum << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}