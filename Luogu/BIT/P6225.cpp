
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct OBIT {
    vector <int> bit;
    int n;

    OBIT (int x = 0) : n(x) {
        bit.assign (n + 5, 0);
    }

    static int lowbit (int x) {
        return (x & -x);
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit(i)) {
            bit[i] ^= k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            ans ^= bit[i];
        }

        return ans;
    }
};

struct BIT {
    vector <int> bit;
    int n;

    BIT (int x = 0) : n(x) {
        bit.assign (n + 5, 0);
    }

    static int lowbit (int x) {
        return (x & -x);
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit(i)) {
            bit[i] ^= k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            ans ^= bit[i];
        }

        return ans;
    }
};

void ovo() {
    int n, q;
    cin >> n >> q;

    vector <int> a (n + 1);
    OBIT obit (n);
    BIT bit (n);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        if (i & 1) {
            obit.point_add ((i + 1) / 2, a[i]);   
        } else {
            bit.point_add (i / 2, a[i]);
        }
    }

    int opt;
    while (q--) {
        cin >> opt;
        if (opt == 1) {
            int i, j;
            cin >> i >> j;
            if (i & 1) {
                obit.point_add ((i + 1)/ 2, (j ^ a[i]));
            } else {
                bit.point_add (i / 2, (j ^ a[i]));
            }

            a[i] = j;
        } else {
            int l, r;
            cin >> l >> r;
            if ((r - l + 1) & 1) {
                if (l & 1) {
                    int bg = (l + 1) / 2;
                    int ed = (r + 1) / 2;
                    cout << (obit.sum (ed) ^ obit.sum (bg - 1)) << '\n'; 
                } else {
                    int bg = l / 2;
                    int ed = r / 2;
                    // cerr << "qj : " << bg << ' ' << ed << '\n';
                    // cerr << bit.sum (ed) << ' ' << bit.sum (bg - 1) << '\n';

                    cout << (bit.sum (ed) ^ bit.sum (bg - 1)) << '\n';
                }
            } else {
                cout << 0 << '\n';
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}