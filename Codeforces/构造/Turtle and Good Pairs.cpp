
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    string s;
    cin >> s;
    vector <int> vis (26);
    for (char & i : s ) {
        vis[i - 'a'] ++;
    }

    string cur;
    while (1) {
        int ok = 0;
        for (int i = 0; i < 26; i ++) {
            if (vis[i]) {
                ok = 1;
                cur += (i + 'a'); vis[i] --;
            }
        }
        if (!ok) break;
    }

    cout << cur << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}