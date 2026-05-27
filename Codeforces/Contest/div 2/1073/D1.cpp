
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    if (n == 2) {
        cout << -1 << '\n';
        return;
    }

    string t;
    int p1, p2;
    for (int i = 0; i < n; i ++) {
        if (s[i] == ')') {
            p1 = i; break;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') {
            p2 = i; break;
        }
    }

    // cerr << p1 << ' ' << p2 << '\n';

    int slow = 0;
    for (int i = 0; i < n; i ++) {
        while (slow == p1 || slow == p2) slow++;
        if (slow > n - 1) {
            cout << -1 << '\n';
            return;
        }
        if (s[i] != s[slow]) {
            if (s[i] == ')' && s[slow] == '(') {
                cout << n - 2 << '\n';
            } else {
                cout << -1 << '\n';
            }
            cerr << i << ' ' << slow << '\n';
            return;
        }
        // cerr << i << ' ' << slow << '\n';
        slow++;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}