
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    unordered_map <int, int> mp;
    vector <int> a (n);

    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    
    if (mp.size() == 1) {
        cout << 0 << '\n';
    } else if (mp.size() == 2) {
        int sm = 0;
        for (auto [x, y] : mp) {
            sm += x;
        }    

        int nm1 = 0, x = a[0];
        for (int i = 0; i < mp[x]; i ++) {
            if (a[i] != x) nm1++;
        }

        int nm2 = 0, y = sm - x;
        for (int i = 0; i < mp[y]; i ++) {
            if (a[i] != y) nm2++;
        }

        cout << min (nm1, nm2) << '\n';
    } else {
        vector <int> p (3);
        iota(p.begin(), p.end(), 1LL);
        
        int mn = 4 * n;
        do {
            int x = mp[p[0]], y = mp[p[1]], z = mp[p[2]];

            int cn12 = 0, cn13 = 0, cn21 = 0, cn23 = 0, cn31 = 0, cn32 = 0;
            for (int i = 0; i < x; i ++) {
                if (a[i] == p[1]) cn12++;
                if (a[i] == p[2]) cn13++;
            }

            for (int i = x; i < x + y; i ++) {
                if (a[i] == p[0]) cn21++;
                if (a[i] == p[2]) cn23++;
            }

            for (int i = x + y; i < n; i ++) {
                if (a[i] == p[0]) cn31++;
                if (a[i] == p[1]) cn32++;
            }

            int now = 0;
            int t1 = min (cn12, cn21);
            now += t1;
            cn12 -= t1; cn21 -= t1;

            int t2 = min (cn13, cn31);
            now += t2;
            cn13 -= t2; cn31 -= t2;

            int t3 = min (cn23, cn32);
            now += t3;
            cn23 -= t3; cn32 -= t3;

            now += (cn12 + cn21 + cn13 + cn31 + cn23 + cn32) / 3 * 2;
            mn = min (mn, now);
        } while (next_permutation(p.begin(), p.end()));

        cout << mn << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}