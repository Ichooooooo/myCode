
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

const int N = 1e5 + 10;
int dp[N];
void ovo() {
    int n; cin >> n;

    vector <int> a (n);
    int m = 0;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        m += a[i];
    }

    dp[0] = 1;
    
    for (int i = 0; i < n; i ++) {
        for (int j = m - a[i]; j >= 0; j --) {
            if (dp[j]) {
                dp[j + a[i]] |= dp[j];
            }
        }
    }


    int sum = 0;
    for (int i = 1; i <= m; i ++) {
        sum += dp[i];
    }

    cout << sum << '\n';
    for (int i = 1; i <= m; i ++) {
        if (dp[i]) cout << i << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}