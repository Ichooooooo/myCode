
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct BIT {
    int n;
    vector <int> bit;

    BIT (int n) : n (n) {
        bit.assign (n + 5, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }    

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] += k;
        }
    }   

    int sum (int x) {
        int res = 0;
        for (int i = x; i >= 1; i -= lowbit (i)) {
            res += bit[i];
        }

        return res;
    }
};

void ovo() {
    int n, q;
    cin >> n >> q;

    vector <int> lastr (n + 1), lastc (n + 1);

    int cnt = 0;
    BIT bitr (q), bitc (q);
    for (int i = 1; i <= q; i ++) {
        int opt, x;
        cin >> opt >> x;

        if (opt == 1) {
            if (lastr[x] == 0) {
                cnt += n;

                bitr.point_add (i, 1);
                lastr[x] = i;
            } else {
                cnt += (bitc.sum (i) - bitc.sum (lastr[x]));

                bitr.point_add (lastr[x], -1);
                bitr.point_add (i, 1);
                lastr[x] = i;
            }
        } else {
            cnt -= (bitr.sum (i) - bitr.sum (lastc[x]));
            
            // cerr << (bitr.sum (i)) << '\n';
            
            if (lastc[x] != 0)
            bitc.point_add (lastc[x], -1);

            bitc.point_add (i, 1);
            lastc[x] = i;
        }

        cout << cnt << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}