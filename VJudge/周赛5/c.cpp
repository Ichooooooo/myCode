
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, k;
    cin >> n >> k;

    vector <int> a (n + 1);
    for (int i = 1; i<= n; i ++) {
        cin >> a[i];
    }

    int cnt = 0, ans = 0;
    vector <int> vis (k + 1);

    for (int i = 1; i <= k; i ++) {
        if (vis[a[i]] == 0) {
            vis[a[i]]++;
            cnt++;
        } else {
            vis[a[i]]++;
        }
    }

    if (cnt == k) ans ++;

    for (int i = 2; i <= n - k + 1; i ++) {
        if (vis[a[i - 1]] == 1) {
            cnt--;
        }
        vis[a[i - 1]]--;

        if (vis[a[i + k - 1]] == 0) {
            cnt++;
        }
        vis[a[i + k - 1]]++;

        if (cnt == k) ans++;
    }

    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}