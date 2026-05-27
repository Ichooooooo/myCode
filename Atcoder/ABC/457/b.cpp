
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <vector <int> > a (n + 1);

    for (int i = 1; i <= n; i ++) {
        int x; cin >>x;
        a[i].reserve (x);

        for (int j = 1; j <= x; j ++) {
            int y; cin >> y;
            a[i].push_back (y);
        }
    }

    int x, y;
    cin >> x >> y;
    cout << a[x][y - 1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}