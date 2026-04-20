#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int x; cin >> x;
    
    if (x & 1) {
        for (int i = 1; ; i ++) {
            if (!(x & (1LL << i))) {
                cout << (1LL << i) << '\n';
                return;
            }
        }
    } else {
        cout << 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}