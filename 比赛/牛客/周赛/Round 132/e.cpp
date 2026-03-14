
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int a, b, k;
    cin >> a >> b >> k;
    int MX = 10 * b + 10;
    vector <int> vis (MX + 1, 1);
    
    queue <pair<int, int>> qu;

    if (a > MX) {             
        cout << -1 << '\n';
        return;
    }
    
    qu.emplace(a, 0LL);
    vis[a] = 0;

    int ans = -1;
    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();

        if (x == b) {
            ans = y;
            break;
        }

        if (x + k <= MX && vis[x + k]) {
            qu.emplace(x + k, y + 1);
            vis[x + k] = 0;
        }
        
        if (x % 10 != 0) {
            int cur = 0, t = x;
            while (t) {
                cur = cur * 10 + t % 10;
                t /= 10;
            }

            if (cur <= MX && vis[cur]) {
                qu.emplace(cur, y + 1);
                vis[cur] = 0;
            }
            
        }
    }

    cout << ans << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}