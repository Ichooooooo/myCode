// 1h + answer
#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long w,h,a,b;
    cin >> w >> h >> a >> b;
    long long x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2) {
        cout << (llabs(y1 - y2) % b == 0 ? "Yes\n" : "No\n");
        return;
    }
    if (y1 == y2) {
        cout << (llabs(x1 - x2) % a == 0 ? "Yes\n" : "No\n");
        return;
    }

    if ( (x1 - x2) % a == 0 || (y1 - y2) % b == 0 ) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
