
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, w; cin >> n >> w;
    vector <int> x(n), y(n);
    for (int i = 0; i < n; i ++) cin >> x[i] >> y[i];

    priority_queue <pair<double,int>> pq;

    for (int i = 0; i < n; i ++) {
        pq.emplace(hypot(x[i], y[i]) - hypot(x[i],y[i] - 1), i);
    }

    while (w && !pq.empty()) {
        auto [_, i] = pq.top(); pq.pop();

        y[i] -= 1;
        w --;

        // cout << i << ' ' << w << '\n';
        if (y[i] > 0) pq.emplace(hypot(x[i], y[i]) - hypot(x[i], y[i] - 1), i);
        // cout << i << '\n';
    }

    double ans = 0;
    for (int i = 0; i < n; i ++) {
        ans += hypot(x[i], y[i]);
    }

    cout << fixed << setprecision(20) <<  ans << '\n';

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}