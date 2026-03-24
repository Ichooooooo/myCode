
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, c, k;
    cin >> n >> c >> k;

    vector <int> a (n);
    for (int & i : a) cin >> i;
    sort (a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        if (a[i] <= c) {
            int nm = min ({c - a[i], k});
            c += (a[i] + nm);
            k -= nm;
        } else {
            break;
        }
    }

    cout << c << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}