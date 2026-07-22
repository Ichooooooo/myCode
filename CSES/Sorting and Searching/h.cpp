
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m, q;
    cin >> n >> m >> q;

    set <int> r, c;
    multiset <int> lenr, lenc;

    r.insert (0); r.insert (m);
    c.insert (0); c.insert (n);

    lenr.insert (m); 
    lenc.insert (n);
    for (int i = 0; i < q; i ++) {
        int opt, k;
        cin >> opt >> k;

        if (opt == 1) {
            auto pos = c.lower_bound(k);
            auto t = lenc.find(*pos - *prev(pos));
            
            lenc.erase (t);
            lenc.insert (*pos - k);
            lenc.insert (k - *prev(pos));
            c.insert(k);
        } else {
            auto pos = r.lower_bound(k);
            auto t = lenr.find(*pos - *prev(pos));
            
            lenr.erase (t);
            lenr.insert (*pos - k);
            lenr.insert (k - *prev(pos));
            r.insert(k);            
        }

        cout << *prev(lenr.end()) * *prev(lenc.end()) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}