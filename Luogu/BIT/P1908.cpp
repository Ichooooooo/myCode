
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

struct BIT {
    int n; 
    vector <int> bit;

    BIT (int x) : n (x) {
        bit.assign (n + 2, 0);
    }

    int lowbit (int x) {
        return (x & (-x));
    }

    void point_add (int x, int k) {
        for (int i = x; i <= n; i += lowbit(i)) {
            bit[i] += k;
        }
    }

    int sum (int x) {
        int ans = 0;
        for (int i = x; i >= 1; i -= lowbit(i)) {
            ans += bit[i];
        }
        return ans;
    }
};

void ovo1() {
    int n; cin >> n;

    vector <int> a (n + 1), b (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        b[i] = a[i];
    } 

    sort (b.begin() + 1, b.end());
    b.erase (unique(b.begin() + 1, b.end()), b.end());

    for (int i = 1; i <= n; i ++) {
        a[i] = lower_bound(b.begin() + 1, b.end(), a[i]) - b.begin();
    }
    
    int m = b.size();
    BIT bit (m);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        ans += i - 1 - bit.sum (a[i]);
        
        // cerr << "bit : " << a[i] << ' ' << bit.sum (a[i]) << '\n';
        
        // cerr << "ans : " << ans << '\n';

        bit.point_add (a[i], 1);
    }

    cout << ans << '\n';
}

const int N = 5e5 + 10;
int a[N], tmp[N];
int ans;

void merge (int l, int r) {
    int mid = l + (r - l) / 2;
    
    if (l >= r) return;

    merge (l, mid);
    merge (mid + 1, r);

    int i = l, j = mid + 1, k = l;

    while (i <= mid && j <= r) {
        if (a[i] > a[j]) {
            ans += (mid - i + 1);
            tmp[k++] = a[j++];
        } else {
            tmp[k++] = a[i++];
        }
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];

    for (int i = l; i <= r; i ++) {
        a[i] = tmp[i];
    }
}

void ovo2() {
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    merge (1, n);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo2();
}