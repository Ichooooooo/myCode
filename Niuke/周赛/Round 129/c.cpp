#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m, k;  cin >> n >> m >> k;
    vector <int> a; a.reserve (n * m);

    priority_queue <int, vector<int>, greater<int>> pq;
    int t;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> t;
            if (t > 0)
            pq.push(t);
        }
    }

    int cnt = 0, nm = 0;
    while (! pq.empty()) {
        int x = pq.top(); pq.pop();
        if (pq.empty()) break;
        if (pq.top() == x) {
            pq.pop();
            pq.push(x + 1); cnt ++;
            if (x + 1 >= k) nm ++;
        }
        cout << x << ' ' << cnt << endl;
    }

    cout << cnt << ' ' << nm << endl;
    // map <int, int> mp;
    // int t;
    // for (int i = 1; i <= n; i ++) {
    //     for (int j = 1; j <= m; j ++) {
    //         cin >> t;
    //         if (t > 0)  {
    //             a.push_back(t);
    //             mp[t] ++;
    //         }
    //     }
    // }

    // ranges :: sort(a.begin(), a.end());
    // a.erase(unique(a.begin(), a.end()), a.end());
    
    // int cnt = 0, nm = 0;
    // for (int i = 0; i < a.size(); i ++) {
    //     if (mp[a[i]] <= 1) continue;
    //     int x = mp[a[i]] / 2;
    //     cnt += x;
    //     mp[a[i] + 1] += x;
    //     if (a[i] + 1 >= k) {
    //         nm += x;
    //     }
    // }

    // if (mp[a[a.size()] + 1]) {
    //     int y = mp[a[a.size()] + 1], x = a[a.size()] + 1;
    //     while (y) {
    //         y >>= 1;
    //         cnt += y;
    //         x ++;
    //         if (x >= k) nm += y;
    //     }
    // }

    // cout << cnt << ' ' << nm << endl;
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