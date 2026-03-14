// sb : 1.输入的下标是1-based, 你用的是0-based但是没有转化
// 2. md读入的是他妈一连串的string, 你用int会把他们当作一个!
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void ovo(){   
    int n; cin >> n;
    vector <string> a (n);
    
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int x1, y1, x2, y2; 
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--; x2--; y2--;

    vector <vector <int>> dis (n, vector<int> (n, -1));

    queue <pair<int, int>> qu;
    qu.emplace(x1, y1);
    dis[x1][y1] = 0;

    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();

        for (int i = 0; i < 4; i ++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx >= 0 && xx < n && yy >= 0 && yy < n && dis[xx][yy] == -1 && a[xx][yy] == '0') {
                dis[xx][yy] = dis[x][y] + 1;
                if (xx == x2 && yy == y2) break;
                qu.emplace(xx, yy);
            }  
        }
    }

    cout << dis[x2][y2] << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}