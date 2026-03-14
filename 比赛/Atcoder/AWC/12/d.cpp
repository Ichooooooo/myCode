
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int INF = 1e6;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void ovo(){   
    int n, m;
    cin >> n >> m;
    vector <string> a (n);
    for (string & i : a)  cin >> i;

    vector <vector<int>> dist (n, vector<int> (m, INF));

    deque <array<int, 2>> dq;
    dq.push_back({0, 0});
    dist[0][0] = (a[0][0] == '#');
    
    while (!dq.empty()) {
        auto [x, y] = dq.front();
        dq.pop_front();

        for (int i = 0; i < 4; i ++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;

            int w = (a[xx][yy] == '#');
            if (dist[x][y] + w < dist[xx][yy]) {
                dist[xx][yy] = dist[x][y] + w;
                if (w == 1) dq.push_back({xx, yy});
                else dq.push_front({xx, yy});
            }
        }
    }

    cout << dist[n - 1][m - 1] << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}