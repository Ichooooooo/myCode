
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> nm (300);
    int ans = 0;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        ans += nm[x + 100];

        // cerr << "i : " << i << ' ' << x << ' ' << nm[x + 100] << '\n';

        for (int i = x + 100; i <= 200; i ++) {
            nm[i] += x;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}