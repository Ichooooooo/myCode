#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int pos = 1, x = 0;
    int ok = 1;
    while (ok) {
        x += pos;
        int cnt = 0;
        for (int i = 1; i * i <= x; i ++) {
            if (x % i == 0) {
                cnt += (i * i == x ? 1 : 2);
            }
        }

        if (cnt > 500) {
            cout << x;ok = 0;
        }
        
        pos++;
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}