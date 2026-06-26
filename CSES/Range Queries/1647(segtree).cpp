
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

const int INF = 1e17;

struct SegTree {
    int n; 
    struct node {
        int l, r;
        int s;
    };
    vector <int> a;
    vector <node> tr;

    SegTree (int n) : n (n) {
        a.assign (n + 1, 0);
        tr.assign (4 * n + 10, {0, 0, 0});
    }

    void push_up (int p) {
        tr[p].s = min (tr[p << 1].s, tr[p << 1 | 1].s);
    }

    void build (int p, int l, int r) {
        // bug0
        tr[p] = {l, r, 0};

        if (l == r) {
            tr[p].s = a[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build (p << 1, l, mid);
        build (p << 1 | 1, mid + 1, r);

        push_up (p);
    }

    void apply (int p, int t) {
        // bug1
        tr[p].s += t;
    }

    void modify (int p, int l, int r, int t) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply (p, t);
            return;
        }

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
    
        if (l <= mid) modify (p << 1, l, r, t);
        if (mid < r) modify (p << 1 | 1, l, r, t);
        
        push_up (p);
    }

    int query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }

        int res = INF;

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        if (l <= mid) res = min(res, query (p << 1, l, r));
        if (mid < r) res = min(res, query (p << 1 | 1, l, r));

        return res;
    }
};


void ovo() {
    int n, q;
    cin >> n >> q;

    SegTree seg (n);
    for (int i = 1; i <= n; i ++) {
        cin >> seg.a[i];
    }

    seg.build (1, 1, n);

    while (q--) {
        int l, r;
        cin >> l >> r;

        cout << seg.query (1, l, r) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}