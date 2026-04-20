
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
const int N = 1000;

int w[6] = {1, 2, 3, 5, 10, 20};
int nm[6] = {};
void ovo() {
    vector <int> dp (N + 5);
    dp[0] = 1;

    for (int i = 0; i < 6; i ++) {
        int x; cin >> x;
        vector <int> ndp (N + 5);
        ndp[0] = 1;

        // cerr << "i : " << i << '\n';
        for (int j = 1; j <= x; j ++) { 
            // cerr << "j : " << j << '\n';
            for (int k = j * w[i]; k <= N; k ++) {
                ndp[k] |= dp[k - j * w[i]];

                // cerr << "k : " << k << ' ' << ndp[k] << '\n';
            }
        }

        // cerr << i << '\n';
        // for (int i = 0; i <= N; i ++) {
        //     cerr << i << ' ' << ndp[i] << '\n';
        // }
        dp = move (ndp);
    }

    int sum = 0;
    for (int i = 0; i <= N; i ++) {
        // cerr << i << ' ' << dp[i] << '\n';
        sum += dp[i];
    }

    cout << "Total=" << sum << '\n';

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}