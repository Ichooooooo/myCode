#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    string s; cin >> s;
    for (int i  = 0; i < 3; i ++) {
        if (s[i] == 'r' || s[i] == 'e' || s[i] == 'd') {
            continue;
        } else {
            cout << "No" << '\n';
            return; 
        }
    }

    cout << "Yes" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}