
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    string s; cin >> s;
    set <char> st;
    map <char, int> mp;
    for (int i = 0; i < s.size(); i ++) {
        mp[s[i]] ++;
    }

    // cout << x << ' ' << y << '\n';
    int mx = 0;
    for (auto [i, j] : mp) {
        mx = max (mx, j);
    }
    for (auto [i, j] : mp) {
        if (j == mx) st.insert(i);
    }

    string t;
    for (int i = 0; i < s.size(); i ++) {
        if (st.find(s[i]) == st.end()) t += s[i];
    }

    cout << t << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}