
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int v, n;
    cin >> v >> n;
    vector <int> a (n);
    for (int & i : a) cin >> i;

    vector <int> dp (v + 1);
    dp[0] = 1;
    
    for (int i = 0; i < n; i ++) {
        for (int j = v; j >= a[i]; j --) {
            dp[j] |= dp[j - a[i]];
        }
    }

    for (int i = v; i >= 0; i --) {
        if (dp[i]) {
            cout << v - i << '\n';
            return;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}