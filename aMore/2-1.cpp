#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <set<int> > v(n + 1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        for (int j = 1; j <= c; j++) {
            int x;
            cin >> x;
            v[i].insert(x);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (v[i].count(x) && v[i].count(y)) ans++;
        }
        cout << ans << '\n';
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}