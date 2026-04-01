
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <vector <pair<int, string>>> g (n + 1);

    priority_queue <pair <string, int>, vector <pair <string, int>>, greater <pair <string, int>>> pq;

    for (int i = 2; i <= n; i ++) {
        int v; string c;
        cin >> v >> c;
        g[v].push_back ({i, c});
        
        if (v == 1) pq.push({c, i});
    }

    cout << 1 << ' ';
    while (!pq.empty()) {
        auto [s, x] = pq.top();
        pq.pop();
        cout << x << ' ';
        for (auto [v, ss] : g[x]) {
            pq.push({s + ss, v});
        }
    }

    cout << '\n';

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}