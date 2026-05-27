
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, k;
    cin >> n >> k;

    vector <vector <int> > a (n + 1);
    vector <int> l (n + 1);
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        l[i] = x;
        for (int j = 0; j < x; j ++) {
            int y; cin >> y;
            a[i].push_back (y);
        }
    }

    vector <int> c (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
    }

    int now = 0;
    for (int i = 1; ; i ++) {
        if ((now + l[i] * c[i]) >= k) {
            // cerr << "i : " << i << '\n';

            int nd = k - now;
            nd = nd % l[i];
            if (nd == 0) {
                cout << a[i][l[i] - 1] << '\n';
            } else {
                cout << a[i][nd - 1] << '\n';
            }
            return; 
        }
        now += l[i] * c[i];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}