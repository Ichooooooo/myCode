
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    for (int l = 1, r = 1e9, mid = l + (r - l) / 2, res; l <= r; mid = l + (r - l) / 2) {
        cout << mid << endl;
        cin >> res;
        if (res == 0) {
            return ;
        } else if (res == -1) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}