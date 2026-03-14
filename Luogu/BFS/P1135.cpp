
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, a, b;
    cin >> n >> a >> b;

    vector <array<int, 2>> dx (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> dx[i][0];
        dx[i][1] = -dx[i][0];
    }

    vector <int> dist (n + 1, -1);
    queue <int> qu;
    qu.push(a);
    dist[a] = 0;

    while (!qu.empty()) {
        int x = qu.front();
        qu.pop();

        for (auto d : dx[x]) {
            int xx = x + d;
            if (xx <= 0 || xx > n || dist[xx] != - 1) continue;

            // cout << xx << ' ' << dist[xx] << '\n';
            dist[xx] = dist[x] + 1;
            qu.push(xx);
        }
    }

    cout << dist[b] << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}