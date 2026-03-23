 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m, k;
    cin >> n >> m >> k;

    if (n == 1 || m == 1) {
        cout << -1 << '\n';
        return;
    }

    int l = 1, r = min (n, m);
    auto cal = [&](int x) -> int {
        return 5 * ((n + m) * x - x * x);
    };

    int pay = 3 * n * m;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (cal(mid) >= pay) r = mid - 1;
        else l = mid + 1;
    }

    cout << l * k << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}