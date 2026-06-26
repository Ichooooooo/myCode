
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, q;
    cin >> n >> q;

    vector <vector <int> > pre (n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i ++) {

        // cerr << "i : " << i << '\n';
        for (int j = 1; j <= n; j ++) {
            char c; cin >> c;

            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + (c == '*');
            // cerr << c;

            // cerr << "j : " << j << ' ' << pre[i][j] << '\n';
        }
        // cerr << '\n';
    }

    while (q --) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int lx1 = min (x1, x2), ly1 = min (y1, y2);
        int rx2 = max (x1, x2), ry2 = max (y1, y2);

        // cerr << pre[lx1][ry2] << '\n';
        cout << pre[rx2][ry2] - pre[lx1 - 1][ry2] - pre[rx2][ly1 - 1] + pre[lx1 - 1][ly1 - 1] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}