
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;
int pre[N];

void ovo() {
    int n; cin >> n;

    int sum = 0, mx = 0;

    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        sum += x;
        mx = max (mx, x);
    }

    cout << max (2 * mx, sum) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}