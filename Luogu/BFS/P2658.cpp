
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void ovo() {
    int n, m; cin >> n >> m;

    vector <vector <int> > a (n + 1, vector <int> (m + 1)), go (n + 1, vector <int> (m + 1));

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
        }
    }

    vector <array<int, 2> > pt; pt.reserve (n);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> go[i][j];

            if (go[i][j] == 1) {
                pt.push_back ({i, j});
            }

        }
    }    

    int l = 0, r = 1e9;
    queue <array <int, 2> > qu;
    auto [px, py] = pt[0];
    

    auto check = [&] (int mid) -> bool {
        qu.push({px, py});
        vector <vector <int> > dist (n + 1, vector <int> (m + 1));
        dist[px][py] = 1;

        while (!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();

            for (int i = 0; i < 4; i ++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                
                if (xx < 1 || xx > n || yy < 1 || yy > m) continue;

                if (dist[xx][yy] != 0) continue;

                if (abs(a[xx][yy] - a[x][y]) > mid) continue;
                
                dist[xx][yy] = 1;
                // cerr << xx << ' ' << yy << '\n';
                qu.push({xx, yy});
            }
        }

        for (int i = 0; i < pt.size(); i ++) {
            auto [x, y] = pt[i];

            if (!dist[x][y]) return false; 
        }

        return true;
    };

    while (l <= r) {
        int mid = l + (r - l) / 2;
        // cerr << mid << '\n';

        if (check (mid)) {
            // cerr << 1;
            r = mid - 1;
        } else {
            // cerr <<2;
            l = mid + 1;
        }
    }

    cout << l << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}