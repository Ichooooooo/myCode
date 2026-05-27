// 1. 树状数组结构体内部int函数， 忘记return int
// 2. 数学变形， 从基本的两个结构出发思考
// 3. 本题目区间查询和区间询问

#include <bits/stdc++.h>
using namespace std;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
#define int long long
const int mod = 1e9 + 7;

struct BIT1 {
    int n; 
    vector <int> bit;

    BIT1 (int x) : n (x) {
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
        for (int i = x; i >= 1; i -= lowbit (i)) {
            ans += bit[i];
        }

        return ans;
    }
};

struct BIT2 {
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
        for (int i = x; i >= 1; i -= lowbit (i)) {
            ans += bit[i];
        }

        return ans;
    }
};

void ovo ()
{
    int n, f; cin >> n >> f;

    vector <int> a (n + 1);
    BIT1 bit1 (n);
    BIT2 bit2 (n);

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        bit1.point_add (i, a[i]);
        bit1.point_add (i + 1, -a[i]);

        bit2.point_add (i, i * a[i]);
        bit2.point_add (i + 1, (i + 1) * (-a[i]));
    }


    while (f --) {
        int opt;
        cin >> opt;

        if (opt == 1) {
            int l, r, k;
            cin >> l >> r >> k;

            bit1.point_add (l, k);
            bit1.point_add (r + 1, -k);
            bit2.point_add (l, l * k);
            bit2.point_add (r + 1, (r + 1) * -k);
        } else if (opt == 2) {
            int k;
            cin >> k;
            
            bit1.point_add (1, k);
            bit1.point_add (1 + 1, -k);  
            bit2.point_add (1, k);
            bit2.point_add (1 + 1, (1 + 1) * -k);      
        } else if (opt == 3) {
            int k;
            cin >> k;
            
            k *= -1;
            bit1.point_add (1, k);
            bit1.point_add (1 + 1, -k);  
            bit2.point_add (1, k);
            bit2.point_add (1 + 1, (1 + 1) * -k);  
        } else if (opt == 4) {
            int l, r;
            cin >> l >> r;

            int s1 = (l - 1 + 1) * bit1.sum (l - 1) - bit2.sum (l - 1);
            int s2 = (r + 1) * bit1.sum (r) - bit2.sum (r);

            cout << s2 - s1 << '\n';
        } else {
            int l = 0, r = 1;

            int s1 = (l + 1) * bit1.sum (l) - bit2.sum (l);
            int s2 = (r + 1) * bit1.sum (r) - bit2.sum (r);

            cout << s2 - s1 << '\n';
        }
    }
} 
    
signed main ()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) ovo();
}