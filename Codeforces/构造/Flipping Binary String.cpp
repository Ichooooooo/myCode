
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    string s; cin >> s;
    
    int cnt = ranges :: count (s, '0');
    if (cnt == 0) {
        if (n & 1) {
            cout << -1 << '\n';
        } else {
            cout << n << '\n';
            for (int i = 1; i <= n; i ++) {
                cout << i << " \n"[i == n];
            }
        }
    } else if (cnt == n) {
        cout << 0 << '\n';
    } else if (cnt & 1) {
        vector <int> ans;
        ans.reserve(n);
        for (int i = 0; i < n; i ++) {
            if (s[i] == '0') {
                ans.push_back(i + 1);
            }
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i ++) {
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
    } else if ((n - cnt) % 2 == 0) {
        vector <int> ans;
        ans.reserve(n);
        for (int i = 0; i < n; i ++) {
            if (s[i] == '1') {
                ans.push_back(i + 1);
            }
        }
        cout << ans.size() << '\n';
        for (int i = 0; i < ans.size(); i ++) {
            cout << ans[i] << " \n"[i == ans.size() - 1];
        }
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