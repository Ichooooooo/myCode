
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

const int INF = 1e15;
const int N = 2e5 + 10;
int a[N];

struct SegTree {
    struct node {
        int l, r;
        int mx, lz;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n) : n (n) {
        a.assign (n + 1, 0);
        tr.assign (4 * n + 10, {0, 0, 0, 0});
    }

    void push_up (int p) {
        tr[p].mx = max (tr[p << 1].mx, tr[p << 1 | 1].mx);
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
        if (l == r) {
            tr[p].mx = a[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build (p << 1, l, mid);
        build (p << 1 | 1, mid + 1, r);

        push_up (p);
    }

    void apply (int p, int k) {
        tr[p].mx += k;
        tr[p].lz += k;
    } 

    void push_down (int p) {
        if (tr[p].lz != 0) {
            apply (p << 1, tr[p].lz);
            apply (p << 1 | 1, tr[p].lz);
            tr[p].lz = 0;
        }
    }

    void modify (int p, int l, int r, int k) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply (p, k);
            return;
        }

        push_down (p);

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        if (l <= mid) modify (p << 1, l, r, k);
        if (mid < r) modify (p << 1 | 1, l, r, k);

        push_up (p);
    }

    int query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].mx;
        }

        push_down (p);
        
        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        int res = -INF;

        if (l <= mid) res = max (res, query (p << 1, l, r));
        if (mid < r) res = max (res, query (p << 1 | 1, l, r));

        return res;
    }

    int query1 (int p, int k) {
        if (tr[p].l == tr[p].r) {
            return tr[p].mx;
        }

        push_down (p);

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        int res = -INF;
        if (k <= mid) res = query1 (p << 1, k);
        else res = query1 (p << 1 | 1, k);

        return res;
    }   
};

void ovo() {
    int n, q; 
    cin >> n >> q;

    vector <int> pre (n + 1);
    SegTree seg (n);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        seg.a[i] = pre[i];

        // cerr << "i : " << i << ' ' << seg.a[i] << '\n';
    }

    seg.build (1, 1, n);
    while (q --) {
        int opt, x, y;
        cin >> opt >> x >> y;

        if (opt == 1) {
            seg.modify (1, x, n, y - a[x]);
            a[x] = y;
        } else {
            // cerr << seg.query (1, x, y) << ' ' << seg.query1 (1, x - 1) << '\n';

            cout << max(0LL, seg.query (1, x, y) - seg.query1 (1, x - 1)) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}