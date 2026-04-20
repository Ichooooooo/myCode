#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n; cin >> n;

    for (int i = 0; i < n; i ++) {
        string s; cin >> s;
        if (s == "and" || s == "not" || s == "that" || s == "the" || s == "you") {
            cout << "Yes" << '\n';
            return;
        }
    }

    cout << "No" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}