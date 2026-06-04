
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    string s;
    cin >> s;

    const int INF = 1e5;
    int mn = INF;
    for (int i = 0; i < s.size() - 2; i ++) {
        string t = s.substr (i, 3);
        int tt = stoll (t);
        mn = min (mn, abs (tt - 753));
    }

    cout << mn << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}