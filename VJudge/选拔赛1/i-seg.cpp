

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

const int N = 2e5 + 10;
int d[N];

struct SegTree {
    struct node {
        int l, r;
        int x;
    };

    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n) : n (n) {
        a.assign (n + 1, 0);
        tr.assign (4 * n + 10, {0, 0, 0});
    }

    void push_up (int p) {
        tr[p].x = gcd (tr[p << 1].x, tr[p << 1 | 1].x);
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0};
        if (l == r) {
            tr[p].x = a[l];
            return;
        }

        int mid = l + (r - l) / 2;
        build (p << 1, l, mid);
        build (p << 1 | 1, mid + 1, r);
        
        push_up (p);
    }

    int query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].x;
        }

        int res = 0;
        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        
        if (l <= mid) res = gcd (res, query(p << 1, l, r));
        if (mid < r) res = gcd (res, query(p << 1 | 1, l, r));

        return res;
    }
};


void ovo() {
    int n;
    cin >> n;
    vector <int> a (n + 1);

    SegTree seg (n);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i ++) {
        seg.a[i] = abs (a[i] - a[i - 1]);
    }

    seg.build (1, 1, n);
    int ans = 1, l = 1;
    for (int r = 1; r <= n; r ++) {

        while (l <= r && seg.query(1, l + 1, r) == 1) l ++;
        
        ans = max (ans, r - l + 1); 
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}