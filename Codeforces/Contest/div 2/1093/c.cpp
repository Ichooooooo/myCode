#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int p, q;
    cin >> p >> q;

    int sum = p + 2 * q;
    
    for (int i = 1; i <= sqrt(sum) + 1; i ++) {
        if ((sum - i) % (2 * i + 1) != 0) continue;
        
        int j = (sum - i) / (2 * i + 1);
        
        if (max (i, j) - min (i, j) <= p) {
            cout << i << ' ' << j << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}