
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;
const int MX = 15000;

class DSU {
    public:
    vector <int> fa, rk, sz;
    DSU (int n = 0) {
        init(n);
    }
    
    void init(int n) {
        fa.resize(n + 1);
        rk.assign(n + 1, 1);
        sz.assign(n + 1, 1);
        ranges :: iota(fa, 0LL);
    } 

    int find (int x) {
        return x == fa[x] ? x : (fa[x] = find(fa[x]));
    }

    bool merge (int i, int j) {
        int x = find(i), y = find(j);
        
        if (x == y) return false;

        if (rk[x] < rk[y]) swap (x, y);
        fa[y] = x;
        if (rk[x] == rk[y]) rk[x] ++;
        sz[x] += sz[y];

        return true;
    } 

    int size (int i) {
        int x = find(i);
        return sz[x];
    }
};

void ovo(){   
    int s, n;
    cin >> s >> n;
    vector <array <int, 2>> a (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    auto check = [&] (double mid) -> bool {
        DSU dsu(n);
        for (int i = 1; i <= n - 1; i ++) {
            for (int j = i + 1; j <= n; j ++) {
                auto [x1, y1] = a[i];
                auto [x2, y2] = a[j];
                double dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if ((mid * mid) >= dis) {
                    dsu.merge(i, j);
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (i == dsu.find(i)) cnt ++;
        }
        if (cnt <= s) return true;
        else return false;
    };

    double l = 0, r = MX;
    while (r - l > 1e-3) {
        double mid = l + (r - l) / 2;
        debug(l); debug(r);
        if (check (mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << fixed << setprecision(2) << l << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}