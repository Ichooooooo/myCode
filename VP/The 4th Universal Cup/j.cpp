
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;

struct BIT1  {
    int n; 
    vector <int> bit;

    BIT1 (int x) : n (x) {
        bit.assign (n + 5, 0);
        for (int i = 1; i <= n; i++) point_add(i, 1);
    } 

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x ;i >= 1; i -= lowbit (i)) {
            ans += bit[i];
        }
        return ans;
    }
};

struct BIT2  {
    int n; 
    vector <int> bit;

    BIT2 (int x) : n (x) {
        bit.assign (n + 5, 0);
    } 

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit (i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x ;i >= 1; i -= lowbit (i)) {
            ans += bit[i];
        }
        return ans;
    }
};

void ovo() {
    int q, c;
    cin >> q >> c;

    vector <arr3> a (q + 1);
    int n = 1, m = 1;
 
    for (int i = 1; i <= q; i ++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        if (a[i][0] == 1) {
            n++;
        } else if (a[i][0] == 2) {
            m++;
        }
    }

    // 存在否
    BIT1 kthx (n);
    BIT1 kthy (m);
    // 位置对应的val
    vector <int> valx (n + 1), valy (m + 1);
    // 位置对应的次数
    vector <int> cntx (n + 1), cnty (m + 1);
    // times对应的位置
    vector <int> posx (q + 1), posy (q + 1);

    for (int i = q; i >= 1; i --) {
        auto [opt, x, y] = a[i];
        if (opt == 3) continue;

        if (opt == 1) {
            int l = 1, r = n, tar = x + 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (kthx.sum (mid) >= tar) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            posx[i] = l;
            valx[l] = y;
            cntx[l] = i;
            kthx.point_add(l, -1);
        } else {
            int l = 1, r = m, tar = x + 1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (kthy.sum (mid) >= tar) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }

            posy[i] = l;
            valy[l] = y;
            cnty[l] = i;
            kthy.point_add(l, -1);
        }
    }

    for (int i = 1; i <= n; i ++) {
        if (valx[i] == 0) {
            valx[i] = c;
            cntx[i] = 0;
            posx[0] = i;
        }
    }

    for (int i = 1; i <= m; i ++) {
        if (valy[i] == 0) {
            valy[i] = c;
            cnty[i] = 0;
            posy[0] = i;
        }
    }

    BIT2 nowx (n), nowy (m);
    nowx.point_add(posx[0], 1);
    nowy.point_add(posy[0], 1);

    for (int i = 1; i <= q; i ++) {
        auto [opt, x, y] = a[i];
        
        if (opt == 1) {
            int p = posx[i];
            nowx.point_add (p, 1);
        } else if (opt == 2) {
            int p = posy[i];
            nowy.point_add (p, 1);
        } else {
            int xl = 1, xr = n;
            while (xl <= xr) {
                int mid = xl + (xr - xl) / 2;
                if (nowx.sum (mid) >= x) {
                    xr = mid - 1;
                } else {
                    xl = mid + 1;
                }
            }
            int yl = 1, yr = m;
            while (yl <= yr) {
                int mid = yl + (yr - yl) / 2;
                if (nowy.sum (mid) >= y) {
                    yr = mid - 1;
                } else {
                    yl = mid + 1;
                }
            }         

            if (cntx[xl] > cnty[yl]) {
                cout << valx[xl] << '\n';
            } else {
                cout << valy[yl] << '\n';
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}