
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, x;
    cin >> n >> x;

    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    sort (a.begin(), a.end());

    int ans = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (l == r) {
            ans++;
            l++; r--;
        } else {
            if (a[l] + a[r] <= x) {
                ans++;
                l ++;
                r --;
            } else {
                ans ++;
                r --;
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}