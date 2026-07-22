
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int x, n; cin  >> x >> n;
    
    vector <int> a (n);
    set <int> pos;
    multiset <int> len;

    pos.insert (0); pos.insert (x);
    len.insert (x);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        auto p1 = pos.lower_bound(a[i]);

        if (p1 == pos.begin()) {
            cout << *prev(len.end()) << ' ';
            continue;
        }

        auto p2 = prev (p1);
        auto t = len.lower_bound (*p1 - *p2);
        len.erase (t);
        len.insert (a[i] - *p2);
        len.insert (*p1 - a[i]);
        pos.insert (a[i]);

        cout << *prev(len.end()) << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}