
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, x;
    cin >> n >> x;

    int l = 0, sum = 0, mnl = -1, mn = 1e5;
    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i ++) {
        sum += a[i];
        if (sum >= x) {
            // cerr << "i : " << l << ' ' << i << ' ' << sum << '\n';
            int len = i - l + 1;
            if (len < mn) {
                mn = len;
                mnl = l;
            }

            while (l <= i && sum >= x) {
                sum -= a[l];
                l++;
                int len = i - l + 1;
                // cerr << "ll : " << l << ' ' << i << ' ' << len << ' ' << sum << '\n';
                if (sum >= x && len < mn) {
                    mn = len;
                    mnl = l;
                }                
            }
        }
    }

    cout << mnl + 1 << ' ' << mnl + mn - 1 + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}