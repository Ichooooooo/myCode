#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {       
    int n; cin >> n;
    vector <int> a (n + 2);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector <arr2> b; b.reserve(m);
    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        b.push_back ({r, l});
    }

    vector <int> c (n + 2);
    sort(b.begin(), b.end());
    
    int l = 0;
    for (int i = 0; i < m; i ++) {
        l = max (l, b[i][1]);
        c[b[i][0] + 1] = l;
        
        // cerr << i << ' ' << b[i][1] << ' ' << b[i][0] << ' ' << l << '\n';
    }

    int now = -1;
    for (int i = 1; i <= n + 1; i ++) {
        if (c[i]) {
            now = c[i];
        }  

        if (now == -1) {
            c[i] = 0;
        } else {
            c[i] = now;
        }

        // cerr << "c : " << i << ' ' << c[i] << '\n';
    }

    vector <int> dp (n + 2);
    deque <arr2> dq;
    dq.push_back({0, 0});

    a[n + 1] = 0;
    for (int i = 1; i <= n + 1; i ++) {
        while (dq.size() && dq.front()[1] < c[i]) {
            dq.pop_front();
        }

        // cerr << "c : " << c[i] << '\n';

        if (!dq.empty()) {
            dp[i] = dq.front()[0] + a[i];
        }

        while (dq.size() && dq.back()[0] >= dp[i]) {
            dq.pop_back();
        }

        dq.push_back ({dp[i], i});
        // cerr << "dp : " << dp[i] << '\n';
    }

    cout << dp[n + 1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}