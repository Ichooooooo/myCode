
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, k;
    cin >> n >> k;

    const int N = 1e3 + 5;
    const int INF = 1e8;
    vector <int> b (n + 1), val (n + 1), cos (N, INF);

    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    int sum = 0;
    for (int j = 1; j <= n; j ++) {
        cin >> val[j];
        sum += val[j];
    }

    cos[1] = 0;
    for (int i = 2; i < N; i ++) {
        for (int j = i - 1; j >= 1; j --) {
            int ch = i - j;
            int chu = j / ch;

            if (ch > j) break;
            // cerr << "i : " << i << ' ' << j << ' ' << ch << ' ' << chu << '\n';

            if (j / chu == ch) {
                cos[i] = min (cos[i], cos[j] + 1);
            }
        }
    }

    int mxnm = 20 * n;

    if (k > mxnm) {
        cout << sum << '\n';
        return;
    }

    vector <int> dp (k + 1);

    for (int i = 1; i <= n; i ++) {
        // cerr << "i : " << i << '\n';
        for (int j = k; j >= cos[b[i]]; j --) {
            dp[j] = max (dp[j], dp[j - cos[b[i]]] + val[i]);
        }   
    }

    cout << dp[k] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}