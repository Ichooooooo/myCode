
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 998244353;

int qpow (int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv (int x) {
    return qpow (x, mod - 2);
}

void ovo() {
    int n, s;
    cin >> n >> s;

    vector <int> p (n + 1), w (n + 1);
    vector <int> mxl (n + 1), mxr (n + 1);

    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
    }

    for (int i = s; i >= 1; i --) {
        if (i == s) mxl[i] = p[i];
        else {
            mxl[i] = max (mxl[i + 1], p[i]);
        }
    }

    for (int i = s; i <= n; i ++) {
        if (i == s) mxr[i] = p[i];
        else {
            mxr[i] = max (mxr[i - 1], p[i]); 
        }
    }

    vector <vector <int> > g (n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i ++) {
        cin >> w[i];
    }

    for (int i = s - 1; i >= 1; i --) {
        for (int j = s + 1; j <= n; j ++) {
            int t = inv (w[i] + w[j]);
            g[i][j] = (w[i]) * t % mod; // pao i
            g[j][i] = (w[j]) * t % mod; // pao j
        }
    }

    vector <vector <int> > dp (n + 1, vector <int> (n + 1));
    
    dp[s][s] = 1;

    int ans = 1;
    for (int i = s + 1; i <= n; i ++) {
        if (s == 1) {
            dp[s][i] = dp[s][i - 1] % mod;
        } else {
            dp[s][i] = dp[s][i - 1] * g[i][s - 1] % mod;
        }

        if (p[i] > mxr[i - 1]) {
            ans = (ans + dp[s][i]) % mod;
        }
    }

    for (int i = s - 1; i >= 1; i --) {
        if (s == n) {
            dp[i][s] = dp[i + 1][s] % mod;
        } else {
            dp[i][s] = dp[i + 1][s] * (g[i][s + 1]) % mod;
        }
        
        if (p[i] > mxl[i + 1]) {
            ans = (ans + dp[i][s]) % mod;
        }
    }

    for (int i = s - 1; i >= 1; i --) {
        for (int j = s + 1; j <= n; j ++) {
            int mx1 = max (mxl[i + 1], mxr[j]);
            if (j == n) {
                dp[i][j] = dp[i + 1][j];
            } else {
                dp[i][j] = (dp[i][j] + dp[i + 1][j] * g[i][j + 1] % mod);
            }

            if (p[i] > mx1) {
                ans = (ans + dp[i][j]) % mod;
            }

            int tdp = 0, mx2 = max (mxl[i], mxr[j - 1]);
            if (i == 1) {
                tdp = dp[i][j - 1];
            } else {
                tdp = (dp[i][j - 1] * g[j][i - 1] % mod);
            }   

            if (p[j] > mx2) {
                ans = (ans + tdp) % mod;
            }

            dp[i][j] = (tdp + dp[i][j]) % mod;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}