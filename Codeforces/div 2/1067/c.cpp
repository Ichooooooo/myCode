
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, k;
    cin >> n >> k;
    vector <int> a (n + 1), b (n + 1);
    vector <int> pre (n + 1), premn (n + 1), aftmx (n + 1);

    
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        premn[i] = min (premn[i - 1], pre[i]);
    }

    for (int i = 1; i <= n; i ++) cin >> b[i];

    aftmx[n] = pre[n];
    for (int i = n - 1; i >= 1; i --) {
        aftmx[i] = max (aftmx[i + 1], pre[i]);
    }

    int ans;
    if (k & 1) {
        ans = aftmx[1] + b[1];
        for (int i = 2; i <= n; i ++) {
            ans = max (ans, aftmx[i] - premn[i - 1] + b[i]);
        }
    } else {
        ans = pre[1];
        for (int i = 2; i <= n; i ++) {
            ans = max (ans, pre[i] - premn[i - 1]);
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