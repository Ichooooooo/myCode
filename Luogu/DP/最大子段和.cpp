#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e7 + 9;
const int mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll & i : a) {
        cin >> i;
    }
    ll mx = a[0], ans = a[0];
    for (int i = 1; i < n; i ++) {
        ans = max(ans + a[i], a[i]);
        mx = max(ans, mx);
    }
    cout << max(ans, mx) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}