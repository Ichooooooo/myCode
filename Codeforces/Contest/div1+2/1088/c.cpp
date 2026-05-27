
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, k;
    cin >> n >> k;

    vector <int> a (n + 1), b (n + 1);
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];

    vector <int> vis (n + 1);
    
    for (int i = 1; i <= n - k; i ++) {
        if (a[i] != b[i] && b[i] != -1) {
            cout << "NO" << '\n';
            return;
        }

        // cerr << i << '\n';
        vis[a[i]] = 1;
    }

    for (int i = k + 1; i <= n; i ++) {
        if (a[i] != b[i] && b[i] != -1) {
            cout << "NO" << '\n';
            return;
        }
        // cerr << i << '\n';
        vis[a[i]] = 1;        
    }



    for (int i = n - k + 1; i <= k; i ++) {
        if (b[i] == -1) continue;

        if (vis[b[i]]) {

            // cerr << i << '\n';

            cout << "NO" << '\n';
            return;
        }

        if (b[i] != -1) vis[b[i]] = 1;
    }

    cout << "YES" << '\n';

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}