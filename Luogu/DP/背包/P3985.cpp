
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, w; cin >> n >> w;

    vector <int> c (n), p (n);
    int mn = LLONG_MAX;
    for (int i = 0; i < n; i ++) {
        cin >> c[i] >> p[i];
        mn = min (mn, c[i]);
    }

    vector <vector<int>> a (4);
    for (int i = 0; i < n; i ++) {
        a[c[i] - mn].push_back(p[i]);
    }

    vector <vector<int>> pre (4);
    for (int i = 0; i < 4; i ++) {
        sort (a[i].rbegin(), a[i].rend());
        int pas = 0;
        pre[i].push_back(pas);
        for (int j = 0; j < a[i].size(); j ++) {
            pas += a[i][j];
            pre[i].push_back(pas);            
        }
    }

    int mx = -1;
    for (int i = 0; i <= a[0].size(); i ++) {
        for (int j = 0; j <= a[1].size(); j ++) {
            for (int k = 0; k <= a[2].size(); k ++) {
                for (int p = 0; p <= a[3].size(); p ++) {
                    int cst = i * mn + j * (mn + 1) + k * (mn + 2) + p * (mn + 3);
                    if (cst <= w) {
                        int pri = pre[0][i] + pre[1][j] + pre[2][k] + pre[3][p];
                        mx = max (mx, pri);
                    } 
                }
            }
        }
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}