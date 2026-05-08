
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    vector <map <int, int>> a (3);
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 6; j ++) {
            int x; cin >> x;
            if (x == 4 || x == 5 || x== 6) {
                a[i][x]++;
            }
        }
    }

    int ans = 0;
    for (int i = 4; i <= 6; i ++) {
        for (int j = 4; j <= 6; j ++) {
            if (i == j) continue;
            for (int z = 4; z <= 6; z ++) {
                if (j == z || i == z) continue;
                // cerr << i << ' ' << j << ' ' << z << ' ' << '\n';
                ans = ans + a[0][i] * a[1][j] * a[2][z];
                // cerr << "ans : " << ans << '\n';
            }
        }
    }

    cout << fixed << setprecision(12) << ans * 1.0 / (6 * 6 * 6) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}