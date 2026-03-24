
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, k; cin >> n >> k;
    
    vector <vector <int>> a (n + 1, vector <int> (26));
    vector <string> ss (k);
    for (int i = 0; i < k; i ++) {
        cin >> ss[i];
    }

    for (int i = 0; i < k; i ++) {
        for (int j = 0; j < n; j ++) {
            a[j + 1][ss[i][j] - 'a'] ++;
        }
    }

    vector <int> yz; yz.reserve (100);
    for (int i = 1; i * i <= n; i ++) {
        if (n % i == 0) {
            yz.push_back(i);
            yz.push_back(n / i);
        }
    }

    sort (yz.begin(), yz.end());
    // 长度
    for (int o = 0; o < yz.size(); o ++) {
        int len = yz[o];

        // cerr << len << '\n';

        // 起始点
        string t;
        int okkk = 1;
        for (int i = 1; i <= len; i ++) {
            // 枚举字母
            int okk = 0;
            for (int j = 0; j < 26; j ++) {
                int ok = 1;
                // 枚举每个位置能否满足
                for (int k = i; k <= n; k += len) {
                    if (a[k][j] == 0) {
                        ok = 0;
                        break;
                    }
                }
                if (ok) {
                    t += j + 'a';
                    okk = 1;
                    break;
                }
            }
            if (okk == 0) {
                okkk = 0;
                break;
            } 
        }

        if (okkk) {
            int nm = n / len;
            while (nm --) cout << t;
            cout << '\n';
            return;
        }
    }
}
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}