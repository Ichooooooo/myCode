
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

const int N = 2e5 + 10;
int vis [N];

struct BIT {
    int n;
    vector <int> bit;

    BIT (int n) : n (n) {
        bit.assign (n + 1, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int p, int k) {
        for (int i = p; i <= n; i += lowbit (i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int res = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            res += bit[i];
        }

        return res;
    }

};

void ovo() {
    int n; cin >> n;

    vector <int> xx (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> xx[i];
    }

    BIT bit (n);
    for (int i = 1; i <= n; i ++) {
        bit.point_add (i, 1);
        vis[i] = 1;
    }

    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;

        int l = 1, r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            
            if (bit.sum(mid) < x) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        // cerr << "r : " << l << '\n';
        cout << xx[l] << ' ';
        bit.point_add (l, -1);
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}