
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> n >> m;

    vector <vector <int> > a (n + 1, vector <int> (m + 1));
    vector <int> sum (n + 1);
    for (int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1];
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            sum[i] += a[i][j];
        }

        // cerr << "i : " << sum[i] << '\n';
    }

    int x = (sum[n]) / 2;
    auto pos = upper_bound (sum.begin() + 1, sum.end(), x);

    int r = prev(pos) - sum.begin();
    int nw = *prev(pos);
    int ans = x * (sum[n] - x);

    // cerr << "r : " << r << '\n';

    if (nw == x) {
        cout << ans << '\n';
        for (int i = 1; i <= r; i ++) cout << 'D';
        for (int j = 1; j <= m; j ++) cout << 'R';
        for (int i = r + 1; i <= n; i ++) cout << 'D';
        cout << '\n';
        return;
    }

    int c;
    for (int i = m; i >= 1; i --) {
        nw += a[r + 1][i];
        if (nw == x) {
            c = i;
            break;
        }
    }

    cout << ans << '\n';
    for (int i = 1; i <= r; i ++) {
        cout << 'D';
    }

    for (int i = 1; i <= c - 1; i ++) {
        cout << 'R';
    }

    cout << 'D';
    for (int i = c; i <= m; i ++) {
        cout << 'R';
    }

    for (int i = r + 2; i <= n; i ++) {
        cout << 'D';
    }

    cout << '\n';
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}