
    #include <bits/stdc++.h>
    #define int long long
    using namespace std;
    const int mod = 998244353;

    void ovo() {
        int n; cin >> n;
        vector <int> a (n + 1), hv (n + 1);

        vector <int> res; res.reserve (n);
        for (int i = 1; i <= n; i ++) {
            cin >> a[i];
        }

        for (int i = 1; i <= n; i ++) {
            if (a[i] > n) {
                res.push_back(a[i]);
            } else if (hv[a[i]]) {
                res.push_back (a[i]);
            } else {
                hv[a[i]] = 1;
            }
        }

        sort (res.begin(), res.end());

        int ans = 0, cnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (hv[i]) continue;
            if (res[cnt] > 2 * i) {
                ans++;
                cnt++;
            } else {
                cout << -1 << '\n';
                return;
            }
        }

        cout << ans << '\n';
    }

    signed main() {
        ios::sync_with_stdio(false); cin.tie(0);
        int _=1;
        cin>>_;

        while (_--) ovo();
    }