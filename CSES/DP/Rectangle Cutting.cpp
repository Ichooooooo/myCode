
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int a, b;
    cin >> a >> b;

    const int INF = 1e17;
    vector <vector <int> > dp (a + 1, vector <int> (b + 1, INF));

    for (int i = 1; i <= min (a, b); i ++) {
        dp[i][i] = 0;
    }

    for (int i = 1; i <= a; i ++) {
        for (int j = 1; j <= b; j ++) {
            for (int k = 1; k < i; k ++) {
                dp[i][j] = min (dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            } 
            for (int k = 1; k < j; k ++) {
                dp[i][j] = min (dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
         }
    } 

    cout << dp[a][b] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}