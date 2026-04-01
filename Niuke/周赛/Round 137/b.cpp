
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    deque <char> dq;
    string s; cin >> s;

    int ok = 1;
    for (int i = 0; i < n; i ++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (ok)
            dq.push_back (s[i]);
            else 
            dq.push_front (s[i]);
        } else if (s[i] == '!') {
            ok ^= 1;
        } else {
            if (dq.empty()) continue;
            if (ok) 
            dq.pop_back();
            else 
            dq.pop_front();
        }
    }

    if (dq.empty()) {
        cout << "Empty" << '\n';
    } else {
        while (!dq.empty()) {
            cout << dq.front();
            dq.pop_front();
        }

        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}