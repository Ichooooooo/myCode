
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    string s; cin >> s;
    s[0] -= 1;
    // cout << s << '\n';
    int now = 1;
    for (char & c : s) now += (c - '0');

    if (now < 10) {
        cout << 0 << '\n';
    } else {
        sort (s.rbegin(), s.rend());
        int ans = 0;
        while (now >= 10) {
            now -= (s[ans] - '0');
            ans ++;
        } 
        cout << ans << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}