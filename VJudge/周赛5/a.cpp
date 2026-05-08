
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int h, w;
    cin >> h >> w;
    int x1 = -1, y1 = -1, x2 = -1, y2 = -1;
    for (int i = 0; i < h; i ++) {
        for (int j = 0; j < w; j ++) {
            char x; cin >> x;
            if (x == 'o') {
                if (x1 == -1 && y1 == -1) {
                    x1 = i;
                    y1 = j;
                } else {
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }

    cout << abs (x1 - x2) + abs (y1 - y2) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}