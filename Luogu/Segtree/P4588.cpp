
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
int mod;

struct SegTree {
    int n; 
    struct node {
        int l, r;
        int s;
    };

    vector <node> tr;

    SegTree (int n) : n (n) {
        tr.assign (4 * n + 10, {0, 0, 1});
    }

    void push_up (int p) {
        tr[p].s = (tr[p << 1].s * tr[p << 1 | 1].s) % mod;
    }

    void build (int p, int l, int r) {
        // bug0
        tr[p] = {l, r, 1};

        if (l == r) {
            tr[p].s = 1;
            return;
        }

        int mid = l + (r - l) / 2;
        build (p << 1, l, mid);
        build (p << 1 | 1, mid + 1, r);

        push_up (p);
    }

    void apply (int p, int t) {
        tr[p].s = t;
    } 

    void modify (int p, int pos, int t) {
        if (tr[p].l == tr[p].r) {
            apply (p, t);
            return;
        }

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
    
        if (pos <= mid) modify (p << 1, pos, t);
        else modify (p << 1 | 1, pos, t);
        
        push_up (p);
    }

    int query () {
        return tr[1].s;
    }
};

void ovo() {
    int q;
    cin >> q >> mod;
    
    SegTree seg (q);
    seg.build (1, 1, q);
    for (int i = 1; i <= q; i ++) {
        int opt, m;
        cin >> opt >> m;

        if (opt == 1) {
            seg.modify (1, i, m);
            cout << seg.query() % mod << '\n';
        } else {
            seg.modify (1, m, 1);
            cout << seg.query() % mod << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}