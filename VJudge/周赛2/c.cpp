#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int r, c; cin >> r >> c;
    vector <string> a (r);
    for (int i = 0; i < r; i ++) {
        cin >> a[i];
    }

    for (int i = 0; i < r; i ++) {
        for (int j = 0; j < c; j ++) {
            if (a[i][j] == '#' || a[i][j] == '.') continue;
            
           
            int x = a[i][j] - '0'; a[i][j] = '.';
            for (int k = i - x; k <= i + x; k ++) {
                for (int p = j - x; p <= j + x; p ++) {
                    if (k < 0 || k >= r || p < 0 || p >= c) continue;
                    if (abs (k - i) + abs (p - j) <= x) {
                        if (a[k][p] == '#')
                        a[k][p] = '.';
                    }
                }
            }
        }
    }

    for (int i = 0; i < r; i ++) {
        cout << a[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}