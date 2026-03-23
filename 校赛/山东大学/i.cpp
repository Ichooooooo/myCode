
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> a (n);
    for (int & i : a) cin >> i;

    ranges :: sort (a);
    int ans = 0, an1 = 0, an2 = 1e18;

    for (int i = 0; i < n; i ++) {
        int x = (a[i] + 5) / 6;
        an1 += ((x - 1) * (n - 1 - (i - 1))) + (n - 1 - i);
        // cerr << x << ' ' << an1 << '\n';
    }


    // 在i个敌人之前放
    for (int i = 0; i < n; i ++) {
        int tans = 0;

        for (int j = 0; j < n; j ++) {
            if (j == i) {
                tans += n - 1 - (j - 1);
            }
            if (j < i) {
                tans += (((a[j] + 5) / 6 - 1) * (n - 1 - (j - 1))) + (n - 1 - j);
            } else {
                int x = a[j] / 20 * 3;
                int res = a[j] % 20;
                tans += x * (n - 1 - (j - 1));
                if (res == 0) {
                    tans --;
                    continue;
                }
                int mn = (res + 5) / 6;
                if (mn > 3) mn = 3;
                tans += (mn - 1) * (n - 1 - (j - 1)) + (n - 1 - j);
            }
        }

        an2 = min (an2, tans);
        // cerr << tans << '\n';
    }

    cout << min (an1, an2) << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}