
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e6;

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    int mn = a[n], ans = 0, ps = n, cnt = 0;
    for (int i = n - 1; i >= 1; i --) {
        ans += max (0LL, a[i] - mn);
        if (a[i] < mn) {
            mn = min (mn, a[i]);
            cnt = max (cnt, ps - i - 1);
            ps = i;
        }
    }

    cnt = max (cnt, ps - 1);

    cout << ans + cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}