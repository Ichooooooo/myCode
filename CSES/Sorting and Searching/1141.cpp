
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> a (n), b (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort (b.begin(), b.end());
    b.erase (unique (b.begin(), b.end()), b.end());

    auto id = [&] (int x) {
        return lower_bound(b.begin(), b.end(), x) - b.begin();
    };

    int m = b.size();
    vector <int> pos (m, -1);

    int ans = 1, now = 1, str = 0;
    pos[id(a[0])] = 0;
    for (int i = 1; i < n; i ++) {
        if (pos[id(a[i])] < str) {
            now ++;
            pos[id(a[i])] = i;
        } else {
            ans = max(ans, i - pos[id(a[i])]);
            str = pos[id(a[i])] + 1;
            now = i - pos[id(a[i])];
            pos[id(a[i])] = i;
        }

        ans = max (ans, now);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}