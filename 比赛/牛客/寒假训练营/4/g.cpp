#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    auto f = [](string x) -> string {
        int ans = 1;
        for (char & i : x) ans *= (i - '0');
        string an = to_string (ans);
        return an;
    };

    int mx = 0; 
    string a1, a2;
    string f1, f2;
    auto dfs = [&](string s, int size, auto self) -> void {
        if (size == 18) {
            int cnt = 0;
            string t = s;
            while (s != f (s)) {
                cnt ++;
                s = f (s);
            }
            mx = max (mx, cnt);
            if (cnt == 11) {
                if (a1.empty()) {
                    a1 = t;
                    f1 = f (t);
                }
                else if (f (t) != f1) {
                    a2 = t;
                }
            }
            return;
        }
        char mn;
        if (size == 0) mn = '2';
        else mn = s[size - 1];
        for (char i = mn; i <= '9'; i ++) {
            string t = s + i;
            self (t, size + 1, self);
        }
    };

    dfs ("", 0, dfs);
    // cout << mx << '\n';
    cout << a1 << ' ' << a2 << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}