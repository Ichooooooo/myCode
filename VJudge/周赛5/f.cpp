
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int INF = 1e17;

void ovo() {
    int f, v;
    cin >> f >> v;

    vector <vector <int> > a (f + 1, vector <int> (v + 1)), dp (v + 1, vector <int> (f + 1, -INF));
    for (int i = 1; i <= f; i ++) {
        for (int j = 1; j <= v; j ++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i <= v; i ++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= v; i ++) {
        // cerr << "i : " << i << '\n';

        for (int j = 1; j <= f; j ++) {
            dp[i][j] = max (dp[i - 1][j], dp[i - 1][j - 1] + a[j][i]);
            // cerr << "j : " << j << ' ' <<  dp[i][j] << '\n';
        }
    }

    cout << dp[v][f] << '\n';

    vector <int> ans; ans.reserve (f);

    int pos = v, cnt = f;
    while (cnt >= 1) {
        while (dp[pos][cnt] == dp[pos - 1][cnt]) {
            pos --;
        }

        if (dp[pos][cnt] == dp[pos - 1][cnt - 1] + a[cnt][pos]) {
            ans.push_back (pos);
            pos--;
            cnt--;
        }
    }

    for (int i = ans.size() - 1; i >= 0; i --) {
        cout << ans[i] << ' ';
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}