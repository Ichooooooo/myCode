#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n, s;
    cin >> n >> s;

    vector <arr2> a (n);
    for (int i = 0; i < n; i ++) {
        int x, y, v;
        cin >> x >> y >> v;
        
        a[i][0] = x * x + y * y;
        a[i][1] = v;
    }

    sort (a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i ++) {
        auto [u, v] = a[i];
        ans += v;
        if (ans >= s) {
            cout << fixed << setprecision(12) << sqrtl(u) << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}