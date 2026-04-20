#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <vector <int> > v(n + 1, vector <int> (m + 1));
    int px, py;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) {
                px = i;
                py = j;
            }
        }
    }

    queue <array <int, 3> > q;
    q.push({px, py, 0});
    vector <vector <int> > vis(n + 1, vector <int> (m + 1, 0));
    vector <vector <int> > val(n + 1, vector <int> (m + 1, 1e8));
    vis[px][py] = 1;

    while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();
        val[x][y] = z;
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
            if (vis[xx][yy]) continue;
            if (v[xx][yy] == 0) continue;
            q.push({xx, yy, z + 1});
            vis[xx][yy] = true;
        }
    }

    int mm;
    cin >> mm;
    vector <array <int, 2> > a(mm + 1);
    map <int, int> mp;
    for (int i = 1; i <= mm; i++) {
        int y, x;
        cin >> y >> x;
        a[i][0] = val[x][y];
        a[i][1] = i;
        mp[a[i][0]]++;
    }
    sort(a.begin() + 1, a.end());

    for (int i = 1; i <= mm; i++) {
        if (mp[a[i][0]] != 1) continue;
        if (a[i][0] == 1e8) continue;
        cout << a[i][1] << ' ' << a[i][0];
        return;
    }
    cout << "No winner.";
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