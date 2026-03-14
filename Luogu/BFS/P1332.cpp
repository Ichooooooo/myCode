
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void ovo(){   
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector <array<int, 2>> inf (a), ms (b);
    for (auto & [x, y] : inf)  cin >> x >> y;
    for (auto & [x, y] : ms)  cin >> x >> y;

    vector <vector<int>> dist (n + 1, vector<int> (m + 1, -1));
    queue <array<int, 2>> qu;

    for (int i = 0; i < a; i ++) {
        auto [x, y] = inf[i];
        dist[x][y] = 0;
        qu.push({x, y});
    }

    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();

        for (int i = 0; i < 4; i ++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx <= 0 || xx > n || yy <= 0 || yy > m || dist[xx][yy] != -1) continue;

            dist[xx][yy] = dist[x][y] + 1;
            qu.push({xx, yy});
        }
    }

    for (int i = 0; i < b; i ++) {
        auto [x, y] = ms[i];
        cout << dist[x][y] << '\n';
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}