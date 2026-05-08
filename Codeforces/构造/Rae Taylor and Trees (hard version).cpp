
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

class DSU {
    public: 
        vector <int> fa, rk, sz;
        int comp;
        DSU (int n = 0) {
            init(n); 
        }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            sz.assign(n + 1, 1);
            ranges::iota(fa, 0LL);
            comp = n;
        }

        int find (int x) {
            return x == fa[x] ? x : (fa[x] = find(fa[x]));
        }

        bool merge (int i, int j) {
            int x = find(i), y = find(j);
            if (x == y) return false;
            if (rk[x] < rk[y]) swap(x, y);
            fa[y] = x;
            sz[x] += sz[y]; 
            if (rk[x] == rk[y]) rk[x]++;
            comp--;
            return true;
        }

        int size (int x) {
            return sz[find(x)];
        }
};

void ovo() {
    int n; cin >> n;
    set <int> st;

    DSU dsu (n);
    vector <int> p (n + 1);
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        p[i] = x;
        st.insert (x);
    }

    if (p[1] == n) {
        cout << "No" << '\n';
        return;
    }

    vector <arr2> ans; ans.reserve (n);

    

    if (dsu.comp == 1) {
        cout << "Yes" << '\n';
        for (auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
    } else {
        cout << "No" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}