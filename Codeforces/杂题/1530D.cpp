
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector <int> vis (n + 1), ans (n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (!vis[a[i]]) {
            vis[a[i]] = 1;
            ans[i] = a[i];
            cnt++;
        }
    }

    int now = 1;
    vector <int> self;
    for (int i = 1; i <= n; i ++) {
        if (ans[i]) continue;
        while (vis[now]) {
            now++;
        } 
        ans[i] = now;
        if (ans[i] == i) {
            self.push_back (i);
        }
        vis[now] = 1;
    }

    if (self.size() == 1) {
        int x = self[0];
        int pos = 0;
        for (int i = 1; i <= n; i ++) {
            if (ans[i] == a[x]) {
                swap (ans[i], ans[self[0]]);
                break;
            }
        }
    } else {
        for (int i = 0; i < self.size(); i ++) {
            ans[self[i]] = self[(i + 1) % (int) (self.size())];
        }
    }

    cout << cnt << '\n';
    for (int i = 1; i <= n; i ++) {
        cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}