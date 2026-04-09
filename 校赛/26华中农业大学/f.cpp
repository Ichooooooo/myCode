#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n; cin >> n;

    vector <arr2> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    vector <int> ans (2 * n + 1);
    int cnt = 1;
    auto dfs = [&] (int x, auto self) -> void {
        if (x == 0) {
            return;
        }

        ans[cnt] = x; cnt++;
        // cerr << cnt << ": " << x << '\n';
        self (a[x][0], self);
        ans[cnt] = x; cnt++;
        // cerr << cnt << ": " << x << '\n';
        self (a[x][1], self);
    };  

    dfs (1, dfs);

    vector <int> vis (n + 1);
    for (int i = 1; i <= 2 * n; i ++) {
        if (vis[ans[i]]) {
            cout << ')';
        } else {
            cout << '(';
            vis[ans[i]] = 1;
        }
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}