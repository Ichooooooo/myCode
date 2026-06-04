
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
int mod;

struct SegTree {
    struct node {
        int l, r;
        int s;
        int mul, add;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n) : n(n) {
        a.assign (n + 1, 0);
        tr.assign (4 * n + 10, {0, 0, 0, 1, 0});
    }

    void push_up (int p) {
        tr[p].s = (tr[p << 1].s + tr[p << 1 | 1].s) % mod; 
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 1, 0};
        if (l == r) {
            tr[p].s = a[l] % mod;
            return;
        }

        int mid = l + (r - l) / 2;
        build (p << 1, l, mid);
        build (p << 1 | 1, mid + 1, r);

        push_up (p);
    }

    void apply1 (int p, int k) {
        tr[p].s = k * tr[p].s % mod;
        tr[p].mul = tr[p].mul * k % mod;
        tr[p].add = tr[p].add * k % mod;
    }

    void apply2 (int p, int k) {
        tr[p].s = (tr[p].s + (tr[p].r - tr[p].l + 1) * k % mod) % mod;
        tr[p].add = (tr[p].add + k) % mod;  
    }

    void push_down (int p) {
        apply1 (p << 1, tr[p].mul);
        apply2 (p << 1, tr[p].add);

        apply1 (p << 1 | 1, tr[p].mul);
        apply2 (p << 1 | 1, tr[p].add);

        tr[p].mul = 1;
        tr[p].add = 0;
    }

    void modify (int p, int l, int r, int k, int opt) {
        if (l <= tr[p].l && tr[p].r <= r) {
            if (opt == 1) {
                apply1 (p, k);
            } else {
                apply2 (p, k);
            }
            return;
        }

        push_down (p);

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        if (l <= mid) modify (p << 1, l, r, k, opt);
        if (mid < r) modify (p << 1 | 1, l, r, k, opt);

        push_up (p);
    }

    int query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }

        push_down (p);

        int res = 0;
        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        if (l <= mid) res += query (p << 1, l, r);
        if (mid < r) res += query (p << 1 | 1, l, r);

        return res;
    }
};

void ovo() {
    int n;
    cin >> n >> mod;
    
    SegTree seg (n);
    for (int i = 1; i <= n; i ++) {
        cin >> seg.a[i];
    }

    seg.build (1, 1, n);

    int q; cin >> q;
    while (q --) {
        int opt, x, y, k;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y >> k;
            seg.modify (1, x, y, k % mod, 1);
        } else if (opt == 2) {
            cin >> x >> y >> k;
            seg.modify (1, x, y, k % mod, 2);
        } else {
            cin >> x >> y;

            cout << seg.query (1, x, y) % mod << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}