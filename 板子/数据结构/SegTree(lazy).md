1. 忘记 return
2. 忘记build
3. l 和 tr[p] 大小关系写反
4. 忘记 push_up 和 push_down
5. push_down 懒标记忘记清空
6. 忘记写构造函数

```cpp

struct SegTree {
    int n; 
    struct node {
        int l, r;
        int s, lz;
    };
    vector <int> a;
    vector <node> tr;

    SegTree (int n) : n (n) {
        a.assign (n + 1, 0);
        tr.assign (4 * n + 10, {0, 0, 0, 0});
    }

    void push_up (int p) {
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;
    }

    void build (int p, int l, int r) {
        // bug0
        tr[p] = {l, r, 0, 0};

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
        tr[p].s += (tr[p].r - tr[p].l + 1) * t;
        tr[p].lz += t;
    }

    void push_down (int p) {
        // bug2
        if (tr[p].lz != 0) {
            apply (p << 1, tr[p].lz);
            apply (p << 1 | 1, tr[p].lz);
            tr[p].lz = 0;
        }
    }

    void modify (int p, int l, int r, int t) {
        if (l <= tr[p].l && tr[p].r <= r) {
            apply (p, t);
            return;
        }

        push_down (p);

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
    
        if (l <= mid) modify (p << 1, l, r, t);
        if (mid < r) modify (p << 1 | 1, l, r, t);
        
        push_up (p);
    }

    int query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }

        // bug4
        push_down(p);
        int res = 0;

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        if (l <= mid) res += query (p << 1, l, r);
        if (mid < r) res += query (p << 1 | 1, l, r);

        return res;
    }
};
