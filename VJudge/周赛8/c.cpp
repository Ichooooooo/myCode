
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;

    int t = n, pos = -1;
    for (int i = 0; i < min (40LL, m); i ++) {
        if (t > 2) {
            int tt = sqrt (t);
            if (tt * tt < t) tt++;
            t = tt;
        } else {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << t << '\n';
        return;
    }

    int ch = m - pos;
    cout << t - ch << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}