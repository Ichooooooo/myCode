
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e15;

void ovo() {
    int n, k;
    cin >> n >> k;

    vector <int> a (n + 1), pre (n + 1);
    for (int i = 1; i <= n;i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    vector <int> mn (n + 1);
    mn[0] = 0;
    for (int i = 1; i <= n; i ++) {
        mn[i] = min (mn[i - 1], pre[i]);
    }

    int mx = pre[n];
    for (int i = 1; i <= n; i ++) {
        mx = max (mx, pre[n] + (k - 1) * (pre[i] - mn[i]));
    }

    cout << mx << '\n';

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}