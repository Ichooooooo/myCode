
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int dx[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int dy[8] = {1, -1, -1, 1, 2, -2, -2, 2};

void ovo(){   
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector <vector <int>> dist (n + 1, vector <int> (m + 1, -1));

    dist[x][y] = 0;
    queue<array<int, 2>> qu;
    qu.push({x, y});

    while (!qu.empty()) {
        auto [x, y] = qu.front(); 
        qu.pop();

        for (int i = 0; i < 8; i ++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && dist[xx][yy] == -1) {
                dist[xx][yy] = dist[x][y] + 1;
                qu.push({xx, yy});
            }
        }
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cout << dist[i][j] << " \n"[j == m];
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}