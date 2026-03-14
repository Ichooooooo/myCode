#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

// struct Edge {
//     int to;
//     int w;
// };

// int dijkstra(int n, int src) {
//     vector<int> dist(n + 1, LLONG_MAX);

//     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

//     dist[src] = 0;
//     pq.push({0, src});

//     while (!pq.empty()) {
//         auto [d, u] = pq.top(); pq.pop();

//         if (d != dist[u]) continue;

//         for (int i = 1; i <= n; i ++) {
//             int v = i;
//              if (v == u) continue;
//             int nd = d + (v ^ u);     
//             if (nd < dist[v]) {
//                 dist[v] = nd;
//                 pq.push({nd, v});
//             }
//         }
//     }

//     int ans = 0;
//     for (int i = 1; i <= n; i ++)  ans ^= dist[i];
//     return ans;
// }

void solve(){   
    // for (int i = 1; i <= 100; i ++) {
    //     cout << i << ' ' << dijkstra(i, 1) << endl;
    // }

    // dabiao

    int t;  cin >> t;
    int n;
    while (t --) {
        cin >> n;
        if (n % 4 == 1) cout << 0 << endl;
        else if (n % 4 == 2) cout << n + 1 << endl;
        else if (n % 4 == 3) cout << 1 << endl;
        else cout << n << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}