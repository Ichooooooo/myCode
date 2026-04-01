
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int N = 105;

void ovo() {
    int n; cin >> n;
    vector <int> a (2 * n + 1), pre (2 * n + 1);
    const int MX = 1e10;
    vector <vector <int> > dpx (2 * n + 1, vector <int> (2 * n + 1));
    vector <vector <int> > dpn (2 * n + 1, vector <int> (2 * n + 1, MX));

    for (int i = 1; i <= 2 * n; i ++) dpn[i][i] = 0;

    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    for (int i = 1; i <= 2 * n; i ++) pre[i] = pre[i - 1] + a[i];

    for (int len = 1; len <= n; len ++) {
        for (int l = 1; l <= 2 * n - len + 1; l ++) {
            int r = l + len - 1;
            
            for (int k = l; k < r; k ++) {
                dpx[l][r] = max (dpx[l][r], dpx[l][k] + dpx[k + 1][r] + pre[r] - pre[l - 1]);
                dpn[l][r] = min (dpn[l][r], dpn[l][k] + dpn[k + 1][r] + pre[r] - pre[l - 1]);
            } 
        }
    }

    int mxa = 0, mna = MX;
    for (int i = 0; i <= n; i ++) {
        mxa = max (dpx[1 + i][1 + i + n - 1], mxa);
        mna = min (dpn[1 + i][1 + i + n - 1], mna);
    }

    cout << mna << '\n' << mxa << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}