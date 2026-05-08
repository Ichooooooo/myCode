
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, k;
    cin >> n >> k;
    vector <int> a (n + 1), b (n + 1);

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= 3; j ++) {
            int x; cin >> x;
            a[i] += x;
            b[i] += x;
        }
    }

    sort (b.begin() + 1, b.end());
    for (int i = 1; i <= n; i ++) {
        int x = a[i];
        auto pos = upper_bound(b.begin(), b.end(), x + 300);
        if (pos == b.end()) {
            cout << "Yes" << '\n'; 
        } else {
            int x = pos - b.begin();
            int cnt = n - x + 1;
            if (cnt + 1 <= k) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
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