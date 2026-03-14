
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, k; cin >> n >> k;
    vector <int> a (n);

    for (int & i : a)  cin >> i;
    vector <int> dp (n);
    dp[0] = a[0];

    multiset <int, greater<int>> st; st.insert(a[0]);
    deque <int> dq; dq.push_back(a[0]);

    for (int i = 1; i < n; i ++) {
        if (st.size() > k) {
            int y = dq.front(); dq.pop_front();
            // cout << "delete : " << y << '\n';
            auto z = st.find(y);
            st.erase(z);
        }

        int x = *st.begin();
        dp[i] = x + a[i];
        // cout << dp[i] << '\n';
        st.insert(dp[i]);
        dq.push_back(dp[i]);
    }

    cout << dp[n - 1] << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}