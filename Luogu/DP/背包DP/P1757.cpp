
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, m;
    cin >> m >> n;

    map <int, vector <int> > mpc, mpv;
    for (int i = 0; i < n; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        mpc[c].push_back(a);
        mpv[c].push_back(b);
    }

    auto itc = mpc.begin();
    auto itv = mpv.begin();
    vector <int> dp (m + 1);
    while (itc != mpc.end() && itv != mpv.end()) {
        auto & [keyc, c] = *itc;
        auto & [keyv, v] = *itv;
        int sz = c.size();

        for (int i = m; i >= 1; i --) {
            for (int j = 0; j < sz; j ++) {
                // cerr << "j : " << j << ' ' << c[j] << ' ' << v[j] << '\n';
                if (i < c[j]) continue;
                dp[i] = max(dp[i], dp[i - c[j]] + v[j]);
            }
        }

        itc = next(itc);
        itv = next(itv);
    }

    cout << dp[m] << '\n';  
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}