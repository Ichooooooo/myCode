#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 676767677;

void ovo() {
    int n, m;
    cin >> n >> m;
    vector <int> mit (m + 5), pre (m + 5); // 每分钟坐下的人

    vector <int> a (n + 1); // 第几分钟坐下
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mit[a[i]] ++;
    }

    if (n == 1) {
        if (a[1] == 0) cout << 1 << '\n';
        else cout << 0 << '\n';
        return;
    }

    for (int i = 0; i < m; i ++) {
        if (i == 0) pre[i] = mit[i];
        else {
            pre[i] = pre[i - 1] + mit[i];
        }
        // cerr << pre[i] << '\n';
    }

    int ans = 1;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == 0) continue;
        int mn = m + 10;
        if (i != 1) mn = min (mn, a[i - 1]);
        if (i != n) mn = min (mn, a[i + 1]);

        if (mn >= a[i]) {
            cout << 0 << '\n';
            return;
        }

        if (a[i] == 1) {
            if (mn == 0) {
                ans = ans * (pre[0]) % mod;
            } else {
                cout << 0 << '\n';
                return;
            }

            continue;
        }

        if (mn == a[i] - 1) {
            ans = (ans * pre[a[i] - 1]) % mod;
        } else {
            ans = (pre[a[i] - 1] - (pre[a[i] - 2])) * ans % mod;
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