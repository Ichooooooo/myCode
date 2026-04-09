#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n, k;
    cin >> n >> k;

    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int c; cin >> c; c--;
    int mx = -1, x = a[c];

    int c1 =0;
    for (int i = 0; i <= c; i ++) {
        if ((a[i] ^ (c1 & 1)) != x) {
            c1 ++;
        }
    }

    int c2 =0;
    for (int i = n - 1; i >= c; i --) {
        if ((a[i] ^ (c2 & 1)) != x) {
            c2 ++;
        }
    }

    cout << max (c1, c2) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}