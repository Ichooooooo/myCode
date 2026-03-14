
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

struct Node
{
    char x;
    int y;
};


void ovo(){   
    string s, t;
    cin >> s >> t;

    vector <int> cs, ct;
    string ss, tt;
    int cnt = 0, pos = 0;
    while (pos < s.size() && s[pos] == 'A') {
        cnt ++;
        pos ++;
    }

    cs.push_back(cnt);
    cnt = 0;
    
    for (int i = pos; i < s.size(); i ++) {
        if (s[i] == 'A') cnt ++;
        else {
            ss += s[i];
            cs.push_back(cnt);
            cnt = 0;
        }
    }
    cs.push_back(cnt);
    cnt = 0; pos = 0;

    while (pos < t.size() && t[pos] == 'A') {
        cnt ++;
        pos ++;
    }

    ct.push_back(cnt);
    cnt = 0;

    for (int i = pos; i < t.size(); i ++) {
        if (t[i] == 'A') cnt ++;
        else {
            tt += t[i];
            ct.push_back(cnt);
            cnt = 0;
        }
    }
    ct.push_back(cnt);

    if (ss != tt) {
        cout << -1 << '\n';
    } else {
        int ans = 0;
        int m = cs.size();
        for (int i = 0; i < m; i ++) {
            ans += abs (cs[i] - ct[i]);
        }
        cout << ans << '\n';    
    }

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}