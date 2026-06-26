
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1);
    vector <arr2> even, odd;
    vector <arr2> feven, fodd;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];

        if (i % 2 == 0 && i != n) {
            even.push_back ({a[i], i});
        } else {
            feven.push_back ({a[i], i});
        }
        if ((i & 1) && i != 1) {
            odd.push_back ({a[i], i});
        } else {
            fodd.push_back ({a[i], i});
        }
    }


    sort (even.begin(), even.end());
    sort (feven.rbegin(), feven.rend());

    vector <int> p (n + 1), q (n + 1);
    int c2 = n;
    for (int i = 0; i < even.size(); i ++) {
        auto [x, pos] = even[i];
        p[pos] = c2;
        c2--;
    }
    int c1 = 1;
    for (int i = 0; i < feven.size(); i ++) {
        auto [x, pos] = feven[i];
        p[pos] = c1;
        c1++;
    }

    int cn1 = 0;
    for (int i = 2; i <= n - 1; i ++) {
        if (a[i - 1] + p[i - 1] < a[i] + p[i] && a[i] + p[i] > a[i + 1] + p[i + 1]) {
            cn1++;
        }
    }

    if (cn1 == (n - 1) / 2) {
        for (int i = 1; i <= n; i ++) {
            cout << p[i] << " \n"[i == n];
        }

        return;
    }

    sort (odd.begin(), odd.end());
    sort (fodd.rbegin(), fodd.rend());

    c2 = n;
    for (int i = 0; i < odd.size(); i ++) {
        auto [x, pos] = odd[i];
        q[pos] = c2;
        c2--;
    }
    c1 = 1;
    for (int i = 0; i < fodd.size(); i ++) {
        auto [x, pos] = fodd[i];
        q[pos] = c1;
        c1++;
    }   
    // cerr << 1;
    for (int i = 1; i <= n; i ++) {
        cout << q[i] << " \n"[i == n];
    }
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}