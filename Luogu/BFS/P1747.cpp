
    #include<bits/stdc++.h>
    #define int long long
    using namespace std;
    const int mod = 998244353;

    int dx[12] = {2, -2, 1, -1, 2, -2, 1, -1, 2, -2, 2, -2};
    int dy[12] = {1, -1, 2, -2, -1, 1, -2, 2, 2, -2, -2, 2};

    void ovo(){   
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        vector <vector <int>> dist (100, vector <int> (100, -1));

        dist[1][1] = 0;
        queue<array<int, 2>> qu;
        qu.push({1, 1});

        while (!qu.empty()) {
            auto [x, y] = qu.front();
            qu.pop();

            for (int i = 0; i < 12; i ++) {
                int xx = x + dx[i];
                int yy = y + dy[i];
                if (xx > 0 && yy > 0 && xx < 100 && yy < 100 && dist[xx][yy] == -1) {
                    dist[xx][yy] = dist[x][y] + 1;
                    qu.push({xx, yy});
                }
            }
        }

        cout << dist[x1][y1] << '\n' << dist[x2][y2] << '\n';

    }

    signed main(){
        ios::sync_with_stdio(false); cin.tie(0);
        int _=1;
        // cin>>_;

        while(_--)  ovo();  return 0;
    }