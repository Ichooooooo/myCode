
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 5e4 + 10;
const int INF = 1e7;
int a[N];

static int lowbit (int x) {
    return (x & (-x));
}

struct MXBIT {
    int n;
    vector <int> bit;

    MXBIT (int x) : n (x) {
        bit.assign (n + 5, 0);
    }

    static int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] = max (bit[i], k);
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            ans += bit[i];
        }
        return ans;
    }
};

struct MNBIT {
    int n;
    vector <int> bit;

    MNBIT (int x) : n (x) {
        bit.assign (n + 5, INF);
    }

    static int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] = min (bit[i], k);
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            ans += bit[i];
        }
        return ans;
    }
};


void ovo() {
    int n, q;
    cin >> n >> q;

    MNBIT mnbit (n);
    MXBIT mxbit (n);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        mnbit.point_add (i, a[i]);
        mxbit.point_add (i, a[i]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int mx = 0, mn = INF;
        while (l <= r) {
            int nxt = r - lowbit(r) + 1;
            if (nxt >= l) {
                mx = max (mx, mxbit.bit[r]);
                mn = min (mn, mnbit.bit[r]);
                r -= lowbit(r);
            } else {
                mx = max (mx, a[r]);
                mn = min (mn, a[r]);
                r--;
            }
        }
        
        // cerr << "mx : " <<  mx << ' ' << mn << '\n';
        cout << mx - mn << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}