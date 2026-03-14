
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <int> a(n), b(n);

    for (int & i : a) cin >> i;
    for (int & j : b) cin >> j;

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        ans = gcd(ans, abs(a[i] - b[i]));
    }

    cout << ans << '\n';

    // set <int> st;
    // for (int i = 0; i < n; i ++) {
    //     int t = abs(a[i] - b[i]);
    //     if (t != 0) st.insert(t);
    // }
    
    // while (st.size() != 1) {
    //     int x = *st.begin();
    //     for (auto it = next(st.begin()); it != st.end();) {
    //         int t = *it % x;
    //         if (t == 0) {
    //             it = st.erase(it);
    //             continue;
    //         }
    //         st.insert(t);
    //         it = st.erase(it);
    //     }
    // }
    
    // cout << *st.begin() << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}