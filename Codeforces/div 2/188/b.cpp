
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n);
    vector <vector <int>> pos (n + 1);
    
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        pos[a[i]].push_back (i);
    }

    int ans = 0, mx = n + 1;
    for (int i = n; i >= 1; i--) {
        if (pos[i].empty()) continue;
        int p = lower_bound (pos[i].begin(), pos[i].end(), mx) - pos[i].begin();
        if (p == 0) continue;
        else {
            ans += p;
            mx = pos[i][0];
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}