
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }


    vector <int> ll (n), rr (n);
    stack <int> st;
    for (int i = 0; i < n; i ++) {
        while (!st.empty() && st.top() < a[i]) {
            st.pop();
        }
        ll[i] = st.size();
        // cerr << i << ' ' << st.size() << '\n';
        st.push(a[i]);
    }
    stack <int> sst;
    for (int i = n - 1; i >= 0; i --) {
        while (!sst.empty() && sst.top() < a[i]) {
            sst.pop();
        }
        rr[i]= sst.size();
        // cerr << i << ' ' << st.size() << '\n';
        sst.push(a[i]);
    }

    int mx = -1;
    for (int i = 0; i < n; i ++) {
        mx = max (mx, 1 + ll[i] + rr[i]);
    }

    cout << n - mx << '\n';
}


signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}