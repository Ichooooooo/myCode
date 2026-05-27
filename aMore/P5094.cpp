#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;

struct SegTree {
    struct node {
        int l, r;
        int s, cnt;
    };
    
    int n;
    vector <int> a;
    vector <node> tr;

    SegTree (int n = 0) : n(n) {
        a.assign(n + 1, 0);
        tr.assign(4 * n + 10, {});
    }

    void push_up (int p) {
        tr[p].s = (tr[p << 1].s + tr[p << 1 | 1].s) % mod;
        tr[p].cnt = (tr[p << 1].cnt + tr[p << 1 | 1].cnt) % mod;
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0, 0};
        if (l == r) {
            tr[p].s = a[l] % mod;
            return;
        }
        int mid = l + ((r - l) >> 1);
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        push_up(p);
    }

    void modify (int p, int x, int t) {
        if (tr[p].l == tr[p].r) {
            tr[p].s = (tr[p].s + t) % mod;
            tr[p].cnt = (tr[p].cnt + 1) % mod;
            return;
        }
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (x <= mid) modify(p << 1, x, t);
        else modify(p << 1 | 1, x, t);
        push_up(p);
    }

    array <int, 2> query (int p, int l, int r) {
        if (l > r) {
            return {0, 0};
        } 
        if (l <= tr[p].l && tr[p].r <= r) {
            return {tr[p].s, tr[p].cnt};
        }
        array <int, 2> res = {0, 0};
        int mid = tr[p].l + ((tr[p].r - tr[p].l) >> 1);
        if (l <= mid) {
            array <int, 2> t = query(p << 1, l, r);
            res[0] = (res[0] + t[0]) % mod;
            res[1] = (res[1] + t[1]) % mod;
        }
        if (mid < r) {
            array <int, 2> t = query(p << 1 | 1, l, r);
            res[0] = (res[0] + t[0]) % mod;
            res[1] = (res[1] + t[1]) % mod;
        }
        return res;
    }
};

void solve ()
{
    int n;
    cin >> n;
    vector <array <int, 2> > v(n + 1);
    int m = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i][0] >> v[i][1];
        m = max(m, v[i][1]);
    }
    SegTree seg(m);
    sort(v.begin() + 1, v.end(), [] (auto a, auto b) {
        return a[0] < b[0];
    });
    seg.build(1, 1, m);

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        auto L = seg.query(1, 1, v[i][1]);
        auto R = seg.query(1, min(m, v[i][1] + 1), m);
        int cur = ((L[1] * v[i][1] % mod - L[0] + mod) % mod + (R[0] - v[i][1] * R[1] % mod + mod) % mod) % mod * v[i][0] % mod;
        ans = (ans + cur) % mod;
        seg.modify(1, v[i][1], v[i][1]);
    }

    cout << ans << '\n';
}

int32_t main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}