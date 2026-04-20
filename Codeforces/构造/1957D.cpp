
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <vector <int> > a (35, vector <int> (n + 1)), pre (35, vector <int> (n + 1)), cnt (35, vector <int> (n + 1));
    vector <int> b (n + 1);
    
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
        int x = b[i];
        for (int bit = 0; bit <= 34; bit ++) {
            a[bit][i] = ((x >> bit) & 1);
        }
    }

    for (int i = 0; i <= 34; i ++) {
        for (int j = 1; j <= n; j ++) {
            cnt[i][j] = cnt[i][j - 1];
            pre[i][j] = (pre[i][j - 1] ^ a[i][j]);
            if (pre[i][j]) cnt[i][j]++;
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        int pos = -1, k = b[i];
        while (k) {
            pos++;
            k >>= 1;
        }
        
        int nm1 = cnt[pos][i - 1], nm2 = cnt[pos][n] - cnt[pos][i - 1];
        ans += nm1 * nm2 + (i - nm1) * (n - i + 1 - nm2);
    }

    cout << ans << '\n';
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}