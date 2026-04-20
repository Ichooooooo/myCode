#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    string s; cin >> s;

    for (int i = 1; i <= 6; i ++) {
        double t = (double) (1.0 * i / 7);
        // cerr << t << '\n';
        t *= 1e6;
        string ts = to_string ((int)t);
        if (ts.front() == s[0]) {
            cout << i << '\n';
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}