
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct SegTree {
    struct node {
        int l, r;
        int x, lz;
    };

    int n;
    vector <node> tr;

    SegTree (int n) : n (n) {
        tr.assign (4 * n + 10, {0, 0, 0, 0});
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
        if (l == r) return;

        int mid = l + (r - l) / 2;
        build (p << 1, l, mid);
        build (p << 1 | 1, mid + 1, r);
    }

    void apply (int p) {
        tr[p].lz ^= 1;
        tr[p].x ^= 1;
    }

    void push_down (int p) {
        if (tr[p].lz != 0) {
            apply (p << 1);
            apply (p << 1 | 1);

            tr[p].lz = 0;
        }
    }

    void modify (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply (p);
            return;
        }

        push_down (p);

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        if (l <= mid) modify (p << 1, l, r);
        if (mid < r) modify (p << 1 | 1, l, r);
    }

    int query (int p, int l) {
        if (tr[p].l == tr[p].r) {
            return tr[p].x;
        }

        push_down (p);

        int res = 0;
        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        if (l <= mid) res = query (p << 1, l);
        else res = query (p << 1 | 1, l);

        return res;
    }
};

void ovo() {
    int n, m;
    cin >> n >> m;

    SegTree seg (n);
    seg.build (1, 1, n);

    while (m --) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;

            seg.modify (1, l, r);
        } else {
            int i; cin >> i;

            cout << seg.query (1, i) << '\n';
        }
    } 
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}