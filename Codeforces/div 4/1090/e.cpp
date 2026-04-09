#include <bits/stdc++.h>
#define int long long
using namespace std;

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int ans = -1;
    for (int i = 1; i <= n - 1; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            ans = max (ans, (a[i] ^ a[j]));
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