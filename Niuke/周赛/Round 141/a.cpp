
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n;
    cin >> n;
    
    string s1 = to_string (n);
    for (int i = 0; i < s1.size() / 2; i ++) {
        if (s1[i] != s1[s1.size() - 1 - i]) {
            cout << "NO" << '\n';
            return;
        }
    }

    int j = sqrt (n);
    if (j * j != n) {
        cout << "NO" << '\n';
        return;
    }

    s1 = to_string (j);
    for (int i = 0; i < s1.size() / 2; i ++) {
        if (s1[i] != s1[s1.size() - 1 - i]) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}