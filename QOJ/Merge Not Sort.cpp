
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (2 * n);
    for (int i = 0; i < 2 * n; i ++) {
        cin >> a[i];
        // // cerr << "i : " << a[i] << ' '; 
    }

    vector <vector <int> > b (2 * n + 1);
    int i = 0, j = 1, cnt = 0;
    while (i < 2 * n) {
        b[cnt].push_back (a[i]);
        // // cerr << "ok" << '\n';
        while (j < 2 * n && a[j] < a[i]) {
            // cerr << "ori : " << j << ' ' << cnt  << ' ' << a[j] << '\n';
            b[cnt].push_back (a[j]);
            j ++;
        }

        // cerr << "outri : " << j << ' '  << cnt << ' ' << a[j] << '\n';

        cnt++;
        i = j;
        j = i + 1;
    }

    // for (auto & v : b) {
    //     // cerr << v.size() << '\n';
    // }

    // // cerr << "cnt : " << cnt << '\n';
    vector <int> dp (n + 1);
    
    int m = cnt;

    dp[0] = 1;
    vector <int> pre (n + 1);
    for (int i = 0; i < m; i ++) {
        int sz = b[i].size();
        // // cerr << "i : " << i << ' ' << sz << '\n';
        for (int j = n; j >= sz; j --) {
            if (!dp[j] && dp[j - sz]) {
                pre[j] = i;
                dp[j] |= dp[j - sz];
            }
            // // cerr << "j : " << j << ' ' << dp[j] << '\n';
        }
    }

    // // cerr << "ok : " << dp[n] << '\n';
    if (!dp[n]) {
        cout << -1 << '\n';
        return;
    }

    vector <int> vis (m);

    // for (auto v : b) {
    //     // cerr << "sz : " << v.size() << '\n';
    //     for (auto u : v) {
    //         // cerr << u << ' ';
    //     }
    //     // cerr << '\n';
    // }

    j = n;
    while (j > 0) {
        vis[pre[j]] = 1;
        j -= (int)(b[pre[j]].size());
    }

    for (int i = 0; i < m; i ++) {
        if (vis[i]) {
            for (auto x : b[i]) {
                cout << x << ' ';
            }
        }
    }

    cout << '\n';
    for (int i = 0; i < m; i ++) {
        if (!vis[i]) {
            for (auto x : b[i]) {
                cout << x << ' ';
            }
        }
    }    

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}