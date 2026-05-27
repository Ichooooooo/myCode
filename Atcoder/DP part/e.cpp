
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;
void ovo() {
    int n, w;   
    cin >> n >> w;
    
    vector <int> wt (n + 1), vl (n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> wt[i] >>vl[i];
        mx += vl[i];
    }

    vector <int> dp (mx + 5, INF);
    dp[0] = 0;

    for (int i = 1; i <= n; i ++) {
        for (int j = mx; j >= vl[i]; j --) {
            dp[j] = min (dp[j], dp[j - vl[i]] + wt[i]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= mx; i ++) {
        if (dp[i] <= w) {
            ans = i;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}