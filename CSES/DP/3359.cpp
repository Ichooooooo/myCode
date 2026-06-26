//BFS+记忆化dp
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <vector <char> > a (n + 1, vector <char> (n + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }

    string ans;
    vector <arr2> cur;
    vector <vector <int> > vis (n + 1, vector <int> (n + 1));

    cur.push_back({1, 1});
    vis[1][1] = 1;
    ans += a[1][1];

    for (int sp = 1; sp <= 2 * n - 2; sp ++) {
        char mn = 'Z';

        for (int i = 0; i < cur.size(); i ++) {
            auto [x, y] = cur[i];
            if (x + 1 <= n) mn = min (mn, a[x + 1][y]);
            if (y + 1 <= n) mn = min (mn, a[x][y + 1]);

            // cerr << "x : " << x + 1 << ' ' << y << ' ' << a[x + 1][y] << '\n';
            // cerr << "x : " << x << ' ' << y + 1 << ' ' << a[x][y + 1] << '\n';
        }


        cerr << "i : " << sp << ' ' << mn << '\n';
        ans += mn;

        vector <arr2> nxt;
        
        for (int i = 0; i < cur.size(); i ++) {
            auto [x, y] = cur[i];
            
            if (x + 1 <= n && a[x + 1][y] == mn && !vis[x + 1][y]) {
                nxt.push_back({x + 1, y});
                vis[x + 1][y] = 1;
            }

            if (y + 1 <= n && a[x][y + 1] == mn && !vis[x][y + 1]) {
                nxt.push_back({x, y + 1});
                vis[x][y + 1] = 1;
            }
        }

        cur = move (nxt);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}