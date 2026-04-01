
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort (a.begin(), a.end());

    int ans = 1, nowc = 0, c = 1, front = a[0];
    for (int i = 1; i < n; i ++) {
        if (a[i] - front >= c) {
            ans++;
            front = a[i];
            c++;
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