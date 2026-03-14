// 他妈多测的时候数据没有读完提前return直接re了
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
using i128 = __int128_t;

class DSU {
    public: 
        vector <int> fa, rk, sz;
        DSU (int n = 0) {
            init(n); 
        }

        void init (int n) {
            fa.resize(n + 1);
            rk.assign(n + 1, 1);
            sz.assign(n + 1, 1);
            iota(fa.begin(), fa.end(), 0);
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
            return true;
        }

        int size (int x) {
            return sz[find(x)];
        }
};

void ovo(){   
    int n, h, r;
    cin >> n >> h >> r;

    vector <array<int, 3>> a (n + 1);
    vector <int> bot, upr;
    int okk = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        int ok = 0;
        if (a[i][2] - r <= 0 && a[i][2] + r >= 0) {
            bot.push_back(i);
            ok ++;
        }
        if (h >= a[i][2] - r && h <= a[i][2] + r) {
            upr.push_back(i);
            ok ++;
        }
        if (ok == 2) {
            okk = 1;
        }
    }

    if (okk) {
        cout << "Yes" << '\n';
        return;
    }

    if (bot.empty() || upr.empty()) {
        cout << "No" << '\n';
        return;
    }

    // for (auto [x, y, z] : a) cout << x << ' ' << y << ' ' << z << '\n';
    // for (int & i : bot) cout << i << ' ';
    // cout << '\n';
    // for (int & j : upr) cout << j << ' ';
    DSU dsu(n);
    for (int i = 1; i <= n - 1; i ++) {
        for (int j = i + 1; j <= n; j ++) {
            auto [x1, y1, z1] = a[i];
            auto [x2, y2, z2] = a[j];
            // cout << i << ' ' << j << ' ' << dis << '\n';
            if (i128(4 * r * r) >= (i128)(x1 - x2) * (x1 - x2) + (i128)(y1 - y2) * (y1 - y2) + (i128)(z1 - z2) * (z1 - z2)) {
                dsu.merge(i, j);
            }
        }
    }

    for (int i = 0; i < bot.size(); i ++) {
        for (int j = 0; j < upr.size(); j ++) {
            int x = dsu.find(bot[i]), y = dsu.find(upr[j]);
            if (x == y) {
                cout << "Yes" << '\n';
                return;
            }
        }
    }

    cout << "No" << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}