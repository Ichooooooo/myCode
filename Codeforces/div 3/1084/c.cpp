
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    stack <char> st;
    string s; cin >> s;
    st.push(s[0]);

    for (int i = 1; i < n; i ++) {
        if (st.empty()) st.push(s[i]);
        else {
            char x = st.top();
            if (s[i] == x) st.pop();
            else st.push(s[i]);
        }
    }

    if (st.empty()) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}