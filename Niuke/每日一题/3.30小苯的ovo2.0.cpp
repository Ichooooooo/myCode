
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1), b (n + 1), c (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        c[i] = a[i] * b[i];
    }

    if (n == 1) {
        cout << 0 << '\n';
        return;
    }

    vector <int> pre (n + 5), aft (n + 5);
    for (int i = 1; i <= n; i ++) {
        if (i == 1) pre[i] = c[1];
        else {
            pre[i] = pre[i - 1] + max (0LL, c[i] - c[i - 1]);
        }
    }

    for (int i = n; i >= 1; i--) {
        if (i == n) aft[i] = c[i];
        else {
            aft[i] = aft[i + 1] + max (0LL, c[i] - c[i + 1]);
        }
    }

    int ans = -1;
    for (int i = 1; i <= n; i ++) {
        if (i == 1) ans = aft[i + 1];
        else if (i == n) ans = min (ans, pre[i - 1]);
        else {
            ans = min (ans, pre[i - 1] + aft[i + 1]);
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