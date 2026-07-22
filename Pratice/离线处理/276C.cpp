// 混淆题

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

void ovo() {
    int n, q; 
    cin >> n >> q;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    sort (a.begin() + 1, a.end());
    
    vector <int> pre (n + 5);
    while (q--) {
        int l, r;
        cin >> l >> r;
        pre[l]++;
        pre[r + 1]--;
    } 

    for (int i = 1; i <= n; i ++) {
        pre[i] += pre[i - 1];
    }

    vector <int> cnt; cnt.reserve (n);
    for (int i = 1; i <= n; i ++) {
        if (pre[i]) {
            cnt.push_back(pre[i]);
        }
    }

    sort (cnt.rbegin(), cnt.rend());
    int ans = 0;
    int m = cnt.size();
    for (int i = 0; i < m; i ++) {
        ans += cnt[i] * a[n - i];
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}