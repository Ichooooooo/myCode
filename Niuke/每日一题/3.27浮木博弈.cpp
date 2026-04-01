
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n);
    for (int & i : a) cin >> i;

    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] == 1) cnt++;
        else break;
    }

    if (cnt == n) {
        if (cnt & 1) {
            cout << "Alice" << '\n';
        } else {
            cout << "Bob" << '\n';
        }
    } else {
        if (cnt & 1) {
            cout << "Bob" << '\n';
        } else {
            cout << "Alice" << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}