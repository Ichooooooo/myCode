
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n;
    cin >> n;
    
    vector <array <int, 2>> a (n);

    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    
    for (int i = 0; i < n - 2; i ++) {
        for (int j = i + 1; j < n - 1; j ++) {
            for (int z = j + 1; z < n; z ++) {
                auto [x1, y1] = a[i];
                auto [x2, y2] = a[j];
                auto [x3, y3] = a[z];

                if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) {
                    cout << "Yes" << '\n';
                    return;
                }
            }
        }
    }

    cout << "No" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}