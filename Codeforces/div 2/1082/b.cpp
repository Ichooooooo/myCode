
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo() {   
    int n; cin >> n;
    string s; cin >> s;

    if ((n & 1) && s[0] == 'b') {
        cout << "NO" << '\n';
        return;
    }

    if (n & 1) {
        for (int i = 1; i < n; i += 2) {
            if (s[i] == '?' || s[i + 1] == '?') continue;
            if (s[i] == s[i + 1]) {
                cout << "NO" << '\n';
                return;
            }
        }
    } else {
        for (int i = 0; i < n; i += 2) {
            if (s[i] == '?' || s[i + 1] == '?') continue;
            if (s[i] == s[i + 1]) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}