
    #include <bits/stdc++.h>
    #define int long long
    using namespace std;
    const int mod = 998244353;

    void ovo() {
        int n; cin >> n;
        vector <int> a (n);
        for (int & i : a) cin >> i;

        vector <int> ans (n);
        for (int i = 0; i < n; i ++) {
            int cl = 0, cr = 0;
            for (int j = i + 1; j < n; j ++) {
                if (a[j] > a[i]) cr++;
                else if (a[j] < a[i]) cl++;
            }

            ans[i] = max (cr, cl);
        }

        for (int i = 0; i < n; i ++) cout << ans[i] << " \n"[i == n - 1];
    }

    signed main() {
        ios::sync_with_stdio(false); cin.tie(0);
        int _=1;
        cin>>_;

        while (_--) ovo();
    }