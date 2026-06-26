// 1. 先读数组再 build
// 2. 懒标记互相影响, 该怎么标记
// 3. 

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct SegTree {
    struct node {
        int l, r, len;
        int lz1; // 把所有数全置0/1/2(没作用)
        int lz2; // 是否取反

        int s; // 1 的个数
        int pre1, suf1, mx1, pre0, suf0, mx0; // 维护区间连续 0/1个数
    };

    int n; 
    vector <int> a;
    vector <node> tr;

    SegTree (int n) : n (n) {
        a.assign (n + 1, 0);
        tr.assign (4 * n + 10, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0});
    }

    void push_up (int p) {
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;
        
        tr[p].pre1 = tr[p << 1].pre1;
        if (tr[p << 1].pre1 == tr[p << 1].len) {
            tr[p].pre1 = tr[p << 1].pre1 + tr[p << 1 | 1].pre1;
        }

        tr[p].suf1 = tr[p << 1 | 1].suf1;
        if (tr[p << 1 | 1].suf1 == tr[p << 1 | 1].len) {
            tr[p].suf1 = tr[p << 1 | 1].suf1 + tr[p << 1].suf1;
        }

        tr[p].mx1 = max ({tr[p << 1].suf1 + tr[p << 1 | 1].pre1, tr[p << 1].mx1, tr[p << 1 | 1].mx1});

        // 0 
        tr[p].pre0 = tr[p << 1].pre0;
        if (tr[p << 1].pre0 == tr[p << 1].len) {
            tr[p].pre0 = tr[p << 1].pre0 + tr[p << 1 | 1].pre0;
        }

        tr[p].suf0 = tr[p << 1 | 1].suf0;
        if (tr[p << 1 | 1].suf0 == tr[p << 1 | 1].len) {
            tr[p].suf0 = tr[p << 1 | 1].suf0 + tr[p << 1].suf0;
        }

        tr[p].mx0 = max ({tr[p << 1].suf0 + tr[p << 1 | 1].pre0, tr[p << 1].mx0, tr[p << 1 | 1].mx0});
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, r - l + 1, 2, 0, 0, 0, 0, 0, 0, 0, 0};
        if (l == r) {
            tr[p].s = a[l];
            tr[p].pre1 = (a[l] == 1);
            tr[p].suf1 = (a[l] == 1);
            tr[p].mx1 = (a[l] == 1);
            tr[p].pre0 = (a[l] == 0);
            tr[p].suf0 = (a[l] == 0);
            tr[p].mx0 = (a[l] == 0);

            return;
        }

        int mid = l + (r - l) / 2;
        build (p << 1, l, mid);
        build (p << 1 | 1, mid + 1, r);

        push_up (p);
    }

    void apply0 (int p) {
        tr[p].s = 0;
        tr[p].lz1 = 0;
        tr[p].lz2 = 0;

        tr[p].pre1 = 0;
        tr[p].suf1 = 0;
        tr[p].mx1 = 0;
        tr[p].pre0 = tr[p].len;
        tr[p].suf0 = tr[p].len;
        tr[p].mx0 = tr[p].len;
    }

    void apply1 (int p) {
        tr[p].s = tr[p].len;
        tr[p].lz1 = 1;
        tr[p].lz2 = 0;

        tr[p].pre0 = 0;
        tr[p].suf0 = 0;
        tr[p].mx0 = 0;
        tr[p].pre1 = tr[p].len;
        tr[p].suf1 = tr[p].len;
        tr[p].mx1 = tr[p].len;       
    }

    void apply2(int p) {
        tr[p].s = tr[p].len - tr[p].s;

        swap(tr[p].pre1, tr[p].pre0);
        swap(tr[p].suf1, tr[p].suf0);
        swap(tr[p].mx1, tr[p].mx0);

        tr[p].lz2 ^= 1;
        if (tr[p].lz1 != 2) {
            tr[p].lz1 ^= 1;
            tr[p].lz2 = 0;
        }
    }

    void push_down(int p) {
        if (tr[p].lz1 != 2) {
            if (tr[p].lz1) {
                apply1(p << 1);
                apply1(p << 1 | 1);
            } else {
                apply0(p << 1);
                apply0(p << 1 | 1);
            }
            tr[p].lz1 = 2;
        }

        if (tr[p].lz2) {
            apply2(p << 1);
            apply2(p << 1 | 1);
            tr[p].lz2 = 0;
        }
    }

    void modify (int p, int l, int r, int opt) {
        if (l <= tr[p].l && tr[p].r <= r) {
            if (opt == 0) {
                apply0 (p);
            } else if (opt == 1) {
                apply1 (p);
            } else {
                apply2 (p);
            }
            return;
        }

        push_down (p);

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        if (l <= mid) modify (p << 1, l, r, opt);
        if (mid < r) modify (p << 1 | 1, l, r, opt);

        push_up (p);
    }

    int query1 (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        } 

        push_down (p);

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        int res = 0;
        if (l <= mid) res += query1 (p << 1, l, r);
        if (mid < r) res += query1 (p << 1 | 1, l, r);

        return res;
    }

    struct Info {
        int pre, suf, mx, len;
    };

    Info merge (Info info1, Info info2) {
        Info res;

        res.pre = info1.pre;
        if (info1.pre == info1.len) {
            res.pre = info1.pre + info2.pre;
        }

        res.suf = info2.suf;
        if (info2.suf == info2.len) {
            res.suf = info2.suf + info1.suf;
        }

        res.len = info1.len + info2.len;
        res.mx = max ({info1.suf + info2.pre, info1.mx, info2.mx});  
        
        return res;
    }

    Info query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return {tr[p].pre1, tr[p].suf1, tr[p].mx1, tr[p].len};
        }

        push_down (p);

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        Info info;
        if (r <= mid) {
            return query (p << 1, l, r);
        } else if (l > mid) {
            return query (p << 1 | 1, l, r);
        } else {
            return merge (query (p << 1, l, mid), query (p << 1 | 1, mid + 1, r));
        }
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

    while (m --) {
        int opt; cin >> opt;
        int l, r;
        
        if (opt == 0 || opt == 1 || opt == 2) {
            cin >> l >> r;
            l++, r++;
            seg.modify (1, l, r, opt);
        } else if (opt == 3) {
            cin >> l >> r;
            l++, r++;
            cout << seg.query1 (1, l, r) << '\n';
        } else {
            cin >> l >> r;
            l++, r++;
            auto res = seg.query (1, l, r);

            cout << res.mx << '\n';
        }
    } 
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}