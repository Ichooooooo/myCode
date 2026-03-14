
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n;  cin >> n;
    string s;  cin >> s;
    int ans = -1;
    for (int i = 0; i <= n; i ++) {
        int cnt = 1;
        string t = s.substr(i);
        t += s.substr(0, i);
        // cout << t << '\n';
        for (int j = 0; j < n - 1; j ++) {
            if (t[j] != t[j + 1]) cnt ++;
        }
        ans = max (ans, cnt);
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}