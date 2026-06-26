
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct SegTree {
    struct node {
        int l, r;
        int s;
    };

    int n;
    vector <node> tr;

    SegTree (int n) : n (n) {
        tr.assign (4 * n + 10, {0, 0, 0});
    }

    void push_up (int p) {
        tr[p].s = tr[p << 1].s + tr[p << 1 | 1].s;
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0};
        if (l == r) return;
        
        int mid = l + (r - l) / 2;
        build (p << 1, l, mid);
        build (p << 1 | 1, mid + 1, r);

        push_up (p);
    }

    void modify (int p, int pos, int k) {
        if (tr[p].l == tr[p].r) {
            tr[p].s += k;
            return;
        }

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        
        if (pos <= mid) modify (p << 1, pos, k);
        else modify (p << 1 | 1, pos, k);

        push_up (p);
    }

    int query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].s;
        }

       int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
       int res = 0;

       if (l <= mid) res += query (p << 1, l, r);
       if (mid < r) res += query (p << 1 | 1, l, r);

       return res;
    }
};

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1), b (n + 1);
    for (int i = 1; i<= n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    }

    sort (b.begin() + 1, b.end());
    b.erase (unique(b.begin() + 1, b.end()), b.end());

    int m = b.size();
    for (int i = 1; i <= n; i ++) {
        a[i] = lower_bound (b.begin() + 1, b.end(), a[i]) - b.begin();
    }

    SegTree seg1 (m);
    seg1.build (1, 1, m);
    
    vector <int> nl (n + 1), nr (n + 1);
    for (int i = 1; i <= n; i ++) {
        nl[i] = seg1.query (1, 1, a[i] - 1);

        // cerr << "i : " << i << ' ' << nl[i] << '\n';
        seg1.modify (1, a[i], 1);
    } 

    SegTree seg2 (m);
    seg2.build (1, 1, m);
    for (int i = n; i >= 1; i --) {
        nr[i] = n - i - seg2.query (1, 1, a[i]);

        // cerr << "j : " << i << ' ' << nr[i] << '\n';
        seg2.modify (1, a[i], 1);
    }

    int ans = 0;
    for (int i = 2; i <= n - 1; i ++) {
        ans += nl[i] * nr[i];
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}