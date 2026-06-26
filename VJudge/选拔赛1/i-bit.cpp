// 1. 树状数组和数组对应有问题
// 2. 全局数组提前知道大小, 需要全局变量, 这时候一般取最大值

#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

const int N = 2e5 + 10;
int d[N];

struct BIT {
    int n;
    vector <int> bit;

    BIT (int n) : n (n) {
        bit.assign (n + 5, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int k, int x) {
        for (int i = k; i <= n; i += lowbit(i)) {
            bit[i] = gcd (bit[i], x);
        }
    }

    int query (int l, int r) {
        int res = 0; 
        
        while (r >= l) {
            int low = (r & (-r));
            if (r - low + 1 >= l) {
                res = gcd (res, bit[r]);
                r -= low;
            } else {
                res = gcd (res, d[r]);
                r--;
            }
        }

        return res;
    }
};

void ovo() {
    int n;
    cin >> n;
    vector <int> a (n + 1);

    BIT bit (n);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int i = 2; i <= n; i ++) {
        d[i] = abs (a[i] - a[i - 1]);
        bit.point_add (i, d[i]);
    }

    int ans = 1, l = 1;
    for (int r = 1; r <= n; r ++) {

        while (l <= r && bit.query(l + 1, r) == 1) l ++;
        
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