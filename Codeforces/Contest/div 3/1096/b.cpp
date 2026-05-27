
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    string s; cin >> s;

    if (n & 1) {
        cout << "NO" << '\n';
        return;
    }

    int n1 = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '(') {
            n1++;
        }
    }

    if (n1 == n / 2) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}