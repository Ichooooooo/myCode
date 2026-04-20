
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr5 = array <int, 5>;
using arr2 = array <int, 2>;
using arr3 = array <int, 3>;
const int mod = 1e9 + 7;
const int N = 6;
int dp[N][N][N][N][N];

void ovo() {
    int s; cin >> s;
    
    vector <vector <arr2> > aa (s);
    vector <int> ee (s);
    for (int i = 0; i < s; i ++) {
        int n; cin >> n;
        while (n --) {
            int c, k; cin >> c >> k;
            aa[i].push_back({c, k});
        }

        cin >> ee[i];
    }

    int tb; cin >> tb;
    // jiaqianheshuliang
    vector <arr3> bb (5);
    int sum = 0;
    for (int i = 0; i < tb; i ++) {
        cin >> bb[i][0] >> bb[i][1] >> bb[i][2];
    }

    sort (bb.begin(), bb.end());
    // lisanhua
    unordered_map <int, int> mp;
    for (int i = 0; i < 5; i ++) {
        auto [x, y, z] = bb[i];
        mp[x] = i;
        sum += y * z;
    }
    
    // yinxiao
    vector <arr5> cc (s);
    vector <int> dd (s);
    vector <int> ok (s);
    for (int i = 0; i < s; i ++) {
        int cs = 0;
        for (auto [x, y] : aa[i]) {
            if (mp.find(x) == mp.end()) {
                ok[i] = 1;
                break;
            }
            int z = mp[x];
            cc[i][z] = y;
            cs += bb[z][2] * y;
        }

        dd[i] = cs - ee[i];
    }

    for (int p = 0; p < s; p ++) {
        if (ok[p]) continue;
        auto [a, b, c, d, e] = cc[p];
        for (int i = a; i <= bb[0][1]; i ++) {
            for (int j = b; j <= bb[1][1]; j ++) {
                for (int z = c; z <= bb[2][1]; z ++) {
                    for (int k = d; k <= bb[3][1]; k ++) {
                        for (int h = e; h <= bb[4][1]; h ++) {
                            dp[i][j][z][k][h] = max(dp[i][j][z][k][h], dp[i - a][j - b][z - c][k - d][h - e] + dd[p]);
                        }
                    }
                }
            }
        }
    }

    cout << sum - dp[bb[0][1]][bb[1][1]][bb[2][1]][bb[3][1]][bb[4][1]] << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}