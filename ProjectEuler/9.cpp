
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    const int N = 1000;

    for (int i = 1; i <= 1000; i ++) {
        for (int j = i; j <= 1000; j ++) {
            int c = 1000 - i - j;
            if (c <= 0) break;

            int mx = max (c, j);
            int mn = min (c, j);
            if (mx * mx == mn * mn + i * i) {
                cout << mx * mn * i;
                return;
            }
            
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}