// 1. 熟悉单调栈应用
// 2. dp转移方向可以是拓扑序, 比如本题, 按照高度序转移

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct SegTree {
    struct node {
        int l, r;
        int x;
    };

    int n;
    vector <node> tr;

    SegTree (int n) : n (n) {
        tr.assign (4 * n + 10, {0, 0, 0});
    }

    void push_up (int p) {
        tr[p].x = max (tr[p << 1].x, tr[p << 1 | 1].x);
    }

    void build (int p, int l, int r) {
        tr[p] = {l, r, 0};
        if (l == r) {
            return;
        }

        int mid = l + (r - l) / 2;
        build (p << 1, l, mid);
        build (p << 1 | 1, mid + 1, r);

        push_up (p);
    }

    void modify (int p, int k, int x) {
        if (tr[p].l == tr[p].r) {
            tr[p].x = max (tr[p].x, x);
            return;
        }

        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;
        if (k <= mid) modify (p << 1, k, x);
        else modify (p << 1 | 1, k, x);

        push_up (p);
    }

    int query (int p, int l, int r) {
        if (l <= tr[p].l && tr[p].r <= r) {
            return tr[p].x;
        }

        int res = 0;
        int mid = tr[p].l + (tr[p].r - tr[p].l) / 2;

        if (l <= mid) res = max (res, query (p << 1, l, r));
        if (mid < r) res = max (res, query (p << 1 | 1, l, r));

        return res;
    }
};

void ovo() {
    int n; cin >> n;
    vector <int> h (n + 1);
    vector <arr2> ht (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> h[i];
        ht[i][0] = h[i];
        ht[i][1] = i; 
    }

    stack <int> st;

    vector <int> L (n + 1);
    for (int i = 1; i <= n; i ++) {
        while (st.size() && h[st.top()] < h[i]) {
            st.pop();
        }

        if (st.empty()) L[i] = 0;
        else L[i] = st.top();

        // cerr << "i : " << i << ' ' << L[i] <<'\n';
        st.push(i);
    }

    while (st.size()) st.pop();
    vector <int> R (n + 1);
    
    for (int i = n; i >= 1; i --) {
        while (st.size() && h[st.top()] < h[i]) {
            st.pop();
        }

        if (st.empty()) R[i] = n + 1;
        else R[i] = st.top();

        // cerr << "i : " << i << ' ' << R[i] <<'\n';
        st.push(i);
    }

    sort (ht.begin() + 1, ht.end());

    vector <int> dp (n + 1);
    SegTree seg (n);
    seg.build (1, 1, n);

    for (int i = 1; i <= n; i ++) {
        auto [hi, xi] = ht[i];
        
        dp[xi] = max (seg.query (1, L[xi] + 1, xi), seg.query (1, xi, R[xi] - 1)) + 1;

        // cerr << "i : " << xi << ' ' << dp[xi] << '\n';
        seg.modify (1, xi, dp[xi]);
    }

    int mx = 1;
    for (int i = 1; i <= n; i ++) {
        mx = max (mx, dp[i]);
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}