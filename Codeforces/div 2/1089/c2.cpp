
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int primes[19] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1), b (n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    vector <int> c (n + 1);
    for (int i = 1; i <= n; i ++) {
        if (i == 1) {
            c[i] = gcd (a[i], a[i + 1]);
        } else if (i == n) {
            c[i] = gcd (a[i - 1], a[i]);
        } else {
            int x = gcd(a[i], a[i - 1]);
            int y = gcd(a[i], a[i + 1]);

            c[i] = lcm (x, y);
        }
    }

    const int MN = -1e5;
    vector <vector <int> > dp (n + 1, vector <int> (19, 0));

    for (int i = 1; i <= n; i ++) {
        if (i == 1) {
            for (int j = 0; j < 19; j ++) {
                if (c[i] * primes[j] == a[i]) continue;
                if (c[i] * primes[j] > b[i]) break;

                dp[i][j] = 1;

                // cerr << "1 : " << j << '\n';
            }
        } else {
            // 这个数是什么
            // cerr << i << ": \n";
            for (int j = 0; j < 19; j ++) {
                if (c[i] * primes[j] == a[i]) {
                    for (int k = 0; k < 19; k ++) {
                        if (gcd(a[i], primes[k] * c[i - 1]) == gcd(a[i], a[i - 1]))
                        dp[i][j] = max (dp[i][j], dp[i - 1][k]);
                    }
                    continue;
                }
                if (c[i] * primes[j] > b[i]) break;                
                // 上个数是什么
                int now = primes[j] * c[i];
                // cerr << now << '\n';
                for (int k = 0; k < 19; k ++) {
                    int ps = primes[k] * c[i - 1];

                    // cerr << "pas: " <<  ps << '\n';
                    if (gcd(now, ps) == gcd(a[i], a[i - 1])) {
                        dp[i][j] = max (dp[i][j], dp[i - 1][k] + 1);
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 19; i ++) {
        ans = max (ans, dp[n][i]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}