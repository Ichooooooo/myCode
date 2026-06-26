
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> K (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> K[i];
    }

    stack <int> st;
    vector <int> L (n + 1);
    for (int i = 1; i <= n; i ++) {
        while (st.size() && K[st.top()] >= K[i]) {
            st.pop();
        }

        if (st.empty()) L[i] = 0;
        else L[i] = st.top();
        
        st.push(i);
    }

    while (st.size()) st.pop();

    vector <int> R (n + 1);
    for (int i = n; i >= 1; i --) {
        while (st.size() && K[st.top()] >= K[i]) {
            st.pop();
        }

        if (st.empty()) R[i] = n + 1;
        else R[i] = st.top();

        st.push(i);
    }

    int mx = 0;
    for (int i = 1; i <= n; i ++) {
        int s = K[i] * (R[i] - 1 - (L[i] + 1) + 1);

        // cerr << "i : " << i << ' ' << R[i] - 1 - (L[i] + 1) + 1 << ' ' << K[i] << '\n';
        mx = max (mx, s);
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}