
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    int mx = 0, now;
    if (s[0] == 'a' || s[0] == 'h') now = 1;
    else now = 0;

    for (int i = 1; i < n; i ++) {
        if (s[i] == 'a' && s[i - 1] == 'h') {
            now++;
        } else if (s[i] == 'h' && s[i - 1] == 'a') {
            now++;
        } else {
            mx = max (now, mx);
            if (s[i] == 'a' || s[i] == 'h') {
                now = 1;
            } else {
                now = 0;
            }
        }
        
        // cerr << "i : " << now << '\n';
    }

    mx = max (mx, now);

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}