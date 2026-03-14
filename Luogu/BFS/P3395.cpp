// 第二次犯错 : 因为输入的是1-based坐标, 但是你变量是0-based, 直接越界wa

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

const int INF = 1e4;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void ovo(){   
    int n, m; cin >> n;
    m = 2 * n - 2;

    vector <array<int, 2>> a (m);
    for (auto & i : a)  cin >> i[0] >> i[1];

    const int INF = 1e10;
    
    vector <vector<int>> dist (n, vector<int> (n, -1)), block(n, vector<int> (n, INF));
    for (int i = 1; i <= m; i ++) {
        auto [x, y] = a[i - 1];
        x --, y --;
        block[x][y] = i;
    }

    queue <array<int, 2>> qu;
    qu.push({0, 0});
    dist[0][0] = 0;

    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();

        for (int i = 0; i < 4; i ++) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            
            if (xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
            if (dist[xx][yy] != -1) continue;

            if (dist[x][y] + 1 <= block[xx][yy]) {
                dist[xx][yy] = dist[x][y] + 1;
                qu.push({xx, yy}); 
            }
        }
    }

    if (dist[n - 1][n - 1] == -1) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
    }
    
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}