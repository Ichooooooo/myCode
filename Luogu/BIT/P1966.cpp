
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e8 - 3;

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

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1), b (n + 1);
    vector <int> aa (n + 1), bb (n + 1);
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        aa[i] = a[i];
    }

    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        bb[i] = b[i];
    }

    sort (aa.begin() + 1, aa.end());

    sort (bb.begin() + 1, bb.end());
    
    map <int, int> mp;

    for (int i = 1; i <= n; i ++) {
        a[i] = lower_bound(aa.begin() + 1, aa.end(), a[i]) - aa.begin();
        mp[a[i]] = i;
    }

    for (int i = 1; i <= n; i ++) {
        b[i] = lower_bound(bb.begin() + 1, bb.end(), b[i]) - bb.begin();
        b[i] = mp[b[i]];
    }

    BIT bit (n);
    int ans = 0;
    for (int i = n; i >= 1; i --) {
        ans = (ans + bit.sum (b[i] - 1)) % mod;
        bit.point_add (b[i], 1);
    }
    
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}