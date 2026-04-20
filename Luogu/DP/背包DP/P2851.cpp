
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e12;

void ovo() {
    int n, t; cin >> n >> t;
    vector <int> v (n), c (n);
    
    int mx = 0;
    for (int i = 0; i < n; i ++) {
        cin >> v[i];
        mx = max (mx, v[i]);
    }

    for (int i = 0; i < n; i ++) {
        cin >> c[i];
    }

    vector <int> dp (t + mx + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i ++) {
        
        int k = c[i];

    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}