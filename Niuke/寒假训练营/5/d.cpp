
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

void ovo(){   
    int n;  cin >> n;
    priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> pq;
    int c, w;
    for (int i = 0; i < n; i ++) {
        cin >> c >> w;
        pq.push({w, c});
    }

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    int ans = 0;

    while (!pq.empty()) {
        auto [x, y] = pq.top(); pq.pop();
        // cout << x << ' ' << y << '\n';
        if (y == 0) continue;
        if (y == 1) {
            if (pq.empty()) break;
            auto [x2, y2] = pq.top(); pq.pop();
            ans = (ans + x2 + x) % mod;
            pq.push({x + x2, 1});
            pq.push({x2, y2 - 1});
        } else if (y % 2 == 0) {
            ans = (ans + (x * y) % mod) % mod;
            pq.push({2 * x, (y >> 1)});
        } else {
            auto [x2, y2] = pq.top(); pq.pop();
            ans = (ans + x2 + x) % mod;
            ans = (ans + x * (y - 1)) % mod;
            pq.push({x + x2, 1});
            pq.push({x * 2, (y >> 1)});
            pq.push({x2, y2 - 1});
        }
    }

    cout << ans << '\n';
} 

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        ovo();
    }
    return 0;
}