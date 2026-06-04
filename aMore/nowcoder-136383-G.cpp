#include <bits/stdc++.h>
using namespace std;
#define int long long

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <char> > v(n + 1, vector <char> (m + 1));
    vector <vector <int> > vis(n + 1, vector <int> (m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] == '.') vis[i][j] = true;
        }
    }

    using arr2 = array <int, 2>;
    using arr5 = array <int, 5>;
    vector <arr5> a;
    vector <int> cx(n + 1), cy(m + 1);

    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j <= m; j++) {
            cur += (v[i][j] == '.');
        }
        cx[i] = cur;
    }

    for (int j = 1; j <= m; j++) {
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            cur += (v[i][j] == '.');
        }
        cy[j] = cur;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j]) continue;
            queue <arr2> q;
            q.push({i, j});
            vis[i][j] = true;
            int lx = i, rx = i, ly = j, ry = j;
            int sum = 1;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int xx = x + dx[k];
                    int yy = y + dy[k];
                    if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
                    if (vis[xx][yy]) continue;
                    lx = min(lx, xx);
                    rx = max(rx, xx);
                    ly = min(ly, yy);
                    ry = max(ry, yy);
                    vis[xx][yy] = true;
                    q.push({xx, yy});
                    sum++;
                }
            }
            a.push_back({sum, lx, rx, ly, ry});
            ans = max(ans, sum);
        }
    }

    vector <int> xd(n + 5), yd(m + 5);
    vector <vector <int> > d(n + 5, vector <int> (m + 5));

    auto cal = [&] (int sum, int lx, int rx, int ly, int ry) -> void {
        d[lx][ly] += sum;
        d[rx + 1][ry + 1] += sum;
        d[lx][ry + 1] -= sum;
        d[rx + 1][ly] -= sum;
    };

    for (auto [sum, lx, rx, ly, ry] : a) {
        lx = max(1LL, lx - 1);
        ly = max(1LL, ly - 1);
        rx = min(n, rx + 1);
        ry = min(m, ry + 1);
        xd[lx] += sum;
        xd[rx + 1] -= sum;
        yd[ly] += sum;
        yd[ry + 1] -= sum;
        cal(sum, lx, rx, ly, ry);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        xd[i] += xd[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        yd[i] += yd[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int add = cx[i] + cy[j] - (v[i][j] == '.');
            int cur = add + xd[i] + yd[j] - d[i][j];
            ans = max(ans, cur);
        }
    }

    cout << ans << '\n';
}

int32_t main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}