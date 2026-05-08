
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector <vector <int> > g (n + 1);
    for (int i = 0; i < m; i ++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back (v);
        g[v].push_back (u);
    }

    vector <int> a (k + 1);
    for (int i = 1; i <= k; i ++) {
        cin >> a[i];
    }

    int cp = 0;
    // comp: 所属图编号, isBip: 图是不是二分, col: 二分染色
    vector <int> comp (n + 1), isBip (n + 5), col (n + 1, -1);

    queue <int> qu;
    for (int i = 1; i <= n; i ++) {
        if (col[i] != -1) continue;
        cp++;

        qu.push(i);
        comp[i] = cp;
        col[i] = 0;

        while (qu.size()) {
            int u = qu.front();
            qu.pop();

            for (auto v : g[u]) {
                // if (v == u) continue;

                if (col[v] != -1 && col[v] != (col[u] ^ 1LL)) {
                    isBip[cp] = 1;
                }

                if (col[v] != -1) continue;
                
                col[v] = (col[u] ^ (1LL));
                comp[v] = cp;
                qu.push(v);
            }
        }
    }

    vector<arr2> tag(k + 1);

    for (int i = 1; i <= k; i++) {
        int u = a[i];
        int c = comp[u];

        if (isBip[c]) { 
            // 按你代码含义：isBip[c] == 1 表示这个连通块不是二分图
            tag[i] = {c, -1};
        } else {
            tag[i] = {c, col[u] ^ (i & 1)};
        }
    }

    // for (int i = 1; i <= n; i ++) {
    //     auto [x, y] = tag[i];
    //     // cerr << "tag : " << i << ' ' << x << ' ' << y << '\n';
    // }

    const int INF = 1e15;
    vector <int> nxt (n + 1, INF);

    map <arr2, int> mp;
    for (int i = k; i >= 1; i --) {
        // cerr << "ik : " << ' ' << i << ' ' << a[i] << '\n'; 

        if (mp.find(tag[i]) != mp.end()) {
            nxt[i] = mp[tag[i]];
        }

        mp[tag[i]] = i;
        // cerr << "WTF : " << a[i] << ' ' << x << ' ' << y << ' ' << mp[tag[a[i]]] << '\n';
        // cerr << "ai : " << a[i] << ' ' << ' ' << nxt[i] << '\n';

        // cerr << '\n';
    }

    while (q --)  {
        int l, r;
        cin >> l >> r;

        if (nxt[l] <= r) {
            cout << "Fern" << '\n';
        } else {
            cout << "Stark" << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}