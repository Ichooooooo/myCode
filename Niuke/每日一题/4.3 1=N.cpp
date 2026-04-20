#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n; cin >> n;
    int ans = 0;

    int cnt = 0;
    while (n % 2 == 0) {
        cnt++;
        n /= 2;
    }

    if (cnt) {
        ans += cnt * 2;
    }

    for (int i = 3; i * i <= n; i += 2) {
        int cn = 0;
        while (n % i == 0) {
            cn++;
            n /= i;
        }

        // cerr << i << ' ' << n << ' ' << cn << '\n';
        if (cn) {
            ans += cn * i;
        }
    }

    if (n > 1) ans += n;

    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}