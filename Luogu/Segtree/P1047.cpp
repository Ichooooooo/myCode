
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int x, m;
    cin >> x >> m;

    int cnt = x + 1;
    vector <arr2> a (m);
    for (int i = 0; i < m; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort (a.begin(), a.end());
    
    int mnl = a[0][0], mxr = a[0][1];
    cnt -= mxr - mnl + 1;

    for (int i = 1; i < m; i ++) {
        auto [l, r] = a[i];
        if (mnl <= l && r <= mxr) continue;

        int tl = max (mxr + 1, l);
        cnt -= r - tl + 1;
        mxr = r;
    }

    cout << cnt << '\n'; 
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}