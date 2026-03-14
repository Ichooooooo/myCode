
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    string s;
    cin >> s; s += ' ';
    
    vector <int> prel (n + 1);
    for (int i = 1; i <= n; i ++) {
        prel[i] = prel[i - 1];
        if (s[i] == '(')  prel[i] ++;
    }

    int cnt = 0, p;
    for (int i = 1; i <= n; i ++) {
        if (s[i] == '(') continue;
        else {
            p = i;
            while (i <= n && s[i] == ')') {
                cnt ++;
                i ++;
            }
            // cout << i << ' ';
            break;
        }
    }

    // cout << cnt << ' ' << p << '\n';
    int nm = prel[n] - prel[p];
    // cout << nm << ' ';
    if (nm >= cnt) {
        cout << n - 2 * cnt << '\n';
    } else {
        cout << -1 << '\n';
    }

    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}