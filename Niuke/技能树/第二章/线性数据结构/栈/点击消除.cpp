#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    string s; cin >> s;
    stack <char> st;
    int n = s.size();
    for (int i = 0; i < n; i ++) {
        if (st.empty()) {
            st.push(s[i]);
        } else if (s[i] == st.top()) {
            st.pop();
        } else {
            st.push(s[i]);
        }
    }

    if (st.empty()) {
        cout << 0 << endl;
    } else {
        string ss;
        while (!st.empty()) {
            ss += st.top();
            st.pop();
        }
        reverse(ss.begin(), ss.end());
        cout << ss << endl;
    }
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