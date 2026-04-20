#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    i64 t, h, u;
    cin >> t >> h >> u;
    i64 tu = min(t, u);
    i64 ans = 0;
    ans += tu * 4;
    t -= tu;
    u -= tu;
    if (u) {
        ans += 3 * u;
        ans += 3 * h;
        cout << ans << '\n';
    }else {
        i64 tht = min(t / 2, h);
        ans += tht * 7;
        t -= tht * 2;
        h -= tht;
        if (h && t) {
            i64 th = min(t, h);
            t -= th;
            h -= th;
            ans += th * 5;
        }
        if (h) {
            ans += 3 * h;
            cout << ans << '\n';
        }else if (t) {
            ans += 2 * t + 1;
            cout << ans << '\n';
        }else {
            cout << ans << '\n';
        }
    }
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}