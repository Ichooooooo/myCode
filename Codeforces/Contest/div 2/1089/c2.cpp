
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int primes[19] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 57, 59};

void ovo() {
    int n; cin >> n;
    vector <int> a (n + 1), b (n + 1), c (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    for (int i = 1; i<= n; i ++) {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i ++) {
        if (i == 1) {
            int now = gcd (a[i], a[i + 1]);
            c[i] = (now <= b[i] ? now : a[i]);
        } else if (i == n) {
            int now = gcd (a[i - 1], a[i]);
            c[i] = (now <= b[i] ? now : a[i]);
        } else {
            int now = lcm (gcd (a[i - 1], a[i]),  gcd (a[i + 1], a[i]));
            c[i] = (now <= b[i] ? now : a[i]);
        }

        // cerr << c[i] << ' ';
    }

    // cerr << '\n';

    const int INF = -1e15;
    vector <vector <int> > dp (n + 1, vector <int> (19, INF));

    for (int i = 1; i <= n; i ++) {
        if (i == 1) {
            int pas = gcd (c[i], c[i + 1]);
            for (int j = 0; j < 19; j ++) {
                if (primes[j] * c[i] > b[i] && primes[j] * c[i] != a[i]) break;

                int now = gcd (c[i] * primes[j], c[i + 1]);
                if (now == pas) {
                    dp[i][j] = (c[i] * primes[j] != a[i]);
                }
            }
        } else if (i == n) {
            int rt = gcd (c[i], c[i - 1]);
            for (int j = 0; j < 19; j ++){
                if (primes[j] * c[i] > b[i] && primes[j] * c[i] != a[i]) break;

                for (int k = 0; k < 19; k ++) {
                    int now = gcd (c[i] * primes[j], c[i - 1] * primes[k]);
                    if (now == rt) {
                        dp[i][j] = max (dp[i][j], dp[i - 1][k] + (c[i] * primes[j] != a[i]));
                    }
                }
            }
        } else {
            int rt1 = gcd (c[i], c[i - 1]);
            int rt2 = gcd (c[i], c[i + 1]);
            int rt = lcm (rt2, rt1);
            for (int j = 0; j < 19; j ++) {
                // cerr << i << ": " << primes[j] << ' ' << primes[j] * c[i] << '\n';

                if (primes[j] * c[i] > b[i] && primes[j] * c[i] != a[i]) break;


                for (int k = 0; k < 19; k ++) {
                    int g1 = gcd (c[i] * primes[j], c[i - 1] * primes[k]);
                    int g2 = gcd (c[i] * primes[j], c[i + 1]);
                    int now = lcm (g1, g2);
                    if (g1 == rt1 && g2 == rt2 && now == rt) {
                        dp[i][j] = max (dp[i][j], dp[i - 1][k] + (c[i] * primes[j] != a[i]));
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) {

        // cerr << ranges :: max (dp[i]) << '\n';
        ans = max (ans, ranges :: max (dp[i]));
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}