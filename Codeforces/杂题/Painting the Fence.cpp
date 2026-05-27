
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, q;
    cin >> n >> q;

    vector <int> a (n + 1);
    vector <arr2> b (q);
    for (int i = 0; i < q; i ++) {
        cin >> b[i][0] >> b[i][1];
    }

    for (auto [l, r] : b) {
        for (int i = l; i <= r; i ++) {
            a[i]++;
        }
    }

    vector <int> pre1(n + 1), pre2 (n + 1);
    int tot = 0;
    for (int i = 1; i <= n; i ++) {
        pre1[i] = pre1[i - 1] + (a[i] == 1);
        pre2[i] = pre2[i - 1] + (a[i] == 2);

        tot += (a[i] > 0);
    }

    vector <int> sl (q);
    for (int i = 0; i < q; i ++) {
        int l = b[i][0], r = b[i][1];
        
        sl[i] = pre1[r] - pre1[l - 1];

        // cerr << "i : " << i << ' ' << l << ' ' << r << ' ' << sl[i] << '\n';
    }

    vector <vector <int> > tls (q, vector <int> (q));

    for (int i = 0; i < q; i ++) {
        for (int j = i + 1; j < q; j ++) {
            int l = max (b[i][0], b[j][0]);
            int r = min (b[i][1], b[j][1]);

            if (l > r) tls[i][j] = 0;
            else {
                tls[i][j] = pre2[r] - pre2[l - 1];
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < q; i ++) {
        for (int j = i + 1; j < q; j ++) {
            ans = max (ans, tot - (sl[i] + sl[j] + tls[i][j]));
        }
    }

    cout << ans << '\n';
} 

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}