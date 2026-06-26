
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, k;
    cin >> n >> k;

    string a, b;
    cin >> a >> b;

    int m = (1LL << k) + 1;

    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] == '1') c1++;
        if (b[i] == '1') c2++;

        if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1')) {
            c3++;
        }
    }

    int n1 = m / 3, n2 = m % 3;
    int a1 = c1 * (n - c1), a2 = c2 * (n - c2), a3 = c3 * (n - c3);
    int ans = n1 * (a1 + a2 + a3);

    // cerr << a1 << ' ' << a2 << ' ' << a3 << '\n';

    if (n2 >= 1) ans += a1;
    if (n2 >= 2) ans += a2;

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}