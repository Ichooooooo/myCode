
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    string s; cin >> s;
    int ok = 1;
    for (int i = 1; i < s.size() - 1; i ++) {
        if (s[i] == '0') {
            ok = 0;
            break;
        }
    }
    if (s.size() == 1 || s[0] != '1' || s[s.size() - 1] == '9' || !ok) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}