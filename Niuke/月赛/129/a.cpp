
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    string s; cin >> s;
    auto pos = s.find ("//");
    if (pos == string :: npos) {
        cout << s << '\n';
    } else {
        string t = s.substr(0, pos);
        if (t.size() == 0) {
            cout << "null" << '\n';
        } else {
            cout << t << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}