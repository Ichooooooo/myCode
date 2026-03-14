#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    string s; cin >> s; int n = s.size();
    stack <char> st;

    int c = -1, p = -1;
    map <char, int> mp;
    mp['{'] = 4; mp['['] = 3; mp['('] = 2; mp['<'] = 1;
    map <char, char> mmp;
    mmp['{'] = '}'; mmp['['] = ']'; mmp['('] = ')'; mmp['<'] = '>';
    for (int i = 0; i < n; i ++) {
        if (st.empty()) {
            st.push(s[i]);
            p = mp[s[i]];
        } else if (s[i] == mmp[st.top()]) {
            // cout << "pop : " << s[i] << endl;
            st.pop();
        } else {
            c = mp[s[i]]; p = mp[st.top()];
            // cout << p << ' ' << c << endl;
            if (c > p) {
                cout << "NO" << endl;
                return;
            } else {
                st.push(s[i]);
                p = c;
            }
        }
    }

    if (st.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}