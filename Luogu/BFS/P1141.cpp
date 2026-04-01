
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > a (n + 1, vector <int> (n + 1)), vis (n + 1, vector <int> (n + 1, 0)), ans (n + 1, vector <int> (n + 1, -1));

    vector <string> ss (n);
    for (int i = 0; i < n; i ++) cin >> ss[i];

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            a[i + 1][j + 1] = ss[i][j] - '0';
        }
    }
    
    queue <array <int, 2> > qu;
    auto bfs = [&] (int p, int q) -> void {
        vector <array <int,2 > > tmp; tmp.reserve (n * n + 1);
        int cnt = 1;

        qu.push({p, q});
        vis[p][q] = 1;
        tmp.push_back ({p, q});

        while (!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();

            for (int i = 0;i < 4; i ++) {
                int xx = x + dx[i];
                int yy = y + dy[i];

                if (xx < 1 || xx > n || yy < 1 || yy > n) continue;
                if (vis[xx][yy]) continue;
                if (!(a[x][y] ^ a[xx][yy])) continue;

                vis[xx][yy] = 1;
                cnt++;
                qu.push({xx, yy});
                tmp.push_back ({xx, yy});
            }
        }

        for (int i = 0; i < tmp.size(); i ++) {
            auto [x, y] = tmp[i];
            
            ans[x][y] = cnt;
        }
    };

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (!vis[i][j]) {
                bfs (i, j);
            }
        }
    }    

    while (m--) {
        int x, y; cin >> x >> y;
         
        cout << ans[x][y] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}