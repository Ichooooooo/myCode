#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n, k, m;
    cin >> n >> k >> m;

    string s(n, '.');
    
    for (int i = 0; i < m; i ++) {
        int x; cin >> x;
        x--;
        s[x] = 'x';
    }

    vector <int> a (n);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (abs(i - j) <= k) {
                a[i] = (a[i] | (1LL << (j)));
            }
        }
    }

    vector <int> dp ((1LL << n) - 1, -1);
    const int INF = 1e5;
    auto dfs = [&] (auto self, int mask, int cnt) -> int {
        if (dp[mask] != -1) return dp[mask];

        if (cnt & 1) {
            dp[mask] = INF;
        } else {
            dp[mask] = -INF;
        }

        bool ok = false;
        for (int i = 0; i < n; i ++) {
            if (s[i] == 'x') continue;
            if ((mask & a[i]) != 0) continue;
            if ((mask >> i) & 1LL) continue;
            ok = true;

            int val = self (self, (mask | (1LL << i)), cnt + 1);

            if (cnt & 1) {
                dp[mask] = min (dp[mask], val);
            } else {
                dp[mask] = max (dp[mask], val);
            }
        }

        if (!ok) {
            dp[mask] = cnt;
        }

        return dp[mask];
    };

    dfs (dfs, 0LL, 0);

    int mask = 0;
    int cnt = 0;
    while (1) {

        int t = -1;

        for (int i = 0; i < n; i ++) {
            if (s[i] == 'x') continue;
            if ((mask >> i ) & 1) continue;
            if ((mask & a[i]) != 0) continue;

            int nxt = (mask | (1LL << i));
            if (dp[mask] == dp[nxt]) {
                t = i;
            }
        }       

        if (t == -1) break;
        if (cnt & 1) {
            s[t] = 'b';
        } else {
            s[t] = 'a';
        }
        mask = (mask | (1LL << t));
        cnt++;
    }

    cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}