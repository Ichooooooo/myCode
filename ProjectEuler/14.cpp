#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int MX = 1e6;

void ovo() {
    auto cal = [] (int x) -> int {
        if (x & 1) {
            x = 3 * x + 1;
        } else {
            x /= 2;
        }
        return x;
    };  

    int mxc = -1, mx = -1;
    for (int i = 1; i <= MX; i ++) {
        int x = i, cnt = 0;
        while (x != 1) {
            x = cal (x);
            cnt++;
        }

        if (cnt > mxc) {
            mxc = cnt;
            mx = i;
        } 
    }

    cout << mxc << '\n' << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}