
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, k;
    cin >> n >> k;
    vector <int> a (n);
    for (int & i : a) cin >>i;
    sort (a.begin(), a.end());

    if (n < 3) {
        cout << "NO" << '\n';
        return;
    }

    int sum = a[0] + a[1] + a[2];
    if (sum <= k) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}