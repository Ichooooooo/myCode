
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct SegTree {
    struct node {
        int l, r;
        int mx;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n) : n (n) {
        a.assign (n + 1, 0);
        tr.assign (4 * n + 10, {0, 0, 0});
    };

    void push_up (int p) {
        tr[p].mx = max (tr[p << 1].mx, tr[p << 1 | 1].mx);
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0};
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
        tr[p].mx -= k;
    }

    void modify (int p, int pos, int k) {
        if (tr[p].l == tr[p].r) {
            apply (p, k);
            return;        
        }

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;

        if (pos <= mid) modify (p << 1, pos, k);
        else modify (p << 1 | 1, pos, k);

        push_up (p);
    }

    int query (int p, int k) {
        if (tr[p].mx < k) {
            return 0;
        }

        if (tr[p].l == tr[p].r) {
            return tr[p].l;
        }

        int res = 0;
        if (tr[p << 1].mx >= k) {
            res = query (p << 1, k);
            // cerr << tr[p << 1].mx << '\n';
        } else {
            res = query (p << 1 | 1, k);
        }

        return res;
    }
};

void ovo() {
    int n, m;
    cin >> n >> m;

    SegTree seg (n);
    for (int i = 1; i <= n; i ++) {
        cin >> seg.a[i];
    }

    seg.build (1, 1, n);

    // for (int i = 1; i <= 4 * n; i ++) {
    //     cerr << "i : " << i << ' ' << seg.tr[i].l << ' ' << seg.tr[i].r << ' ' << seg.tr[i].mx << '\n';
    // }
    for (int i = 1; i <= m; i ++) {
        int x; cin >> x;   
        int p = seg.query (1, x);

        // cerr << '\n';

        cout << p << ' ';
        if (p != 0) 
        seg.modify (1, p, x);
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}