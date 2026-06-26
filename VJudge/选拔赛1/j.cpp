
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    
    vector <vector <int> > pre (5, vector <int> (n + 5));

    for (int i = 1; i <= n; i ++) {
        // // cerr << "i : " << i << '\n';
        for (int j = 0; j < 5; j ++) {
            pre[j][i] = pre[j][i - 1] + ((s[i] - 'A') == j);

            // // cerr << "j : " << j << ' ' << pre[j][i] << '\n';
        }
    }

    int cur = 0;
    vector <int> v = {1, 10, 100, 1000, 10000};

    // for (int i = 0; i < 5; i ++) {
    //     // cerr << "i : " << i <<' ' << v[i] << '\n';
    // }

    vector <int> ok (n + 1);
    for (int i = 1; i <= n; i ++) {
        int x = s[i] - 'A';
        int t = 0;
        for (int j = x + 1; j < 5; j ++) {
            t += pre[j][n] - pre[j][i];
        }

        // cerr << "i : " << i << ' ' << t << '\n';
        if (t > 0) {
            ok[i] = -1;
            cur -= v[x];
        } else {
            ok[i] = 1;
            cur += v[x];
        }

        // cerr << "i : " << i << ' ' << cur << '\n';
    }

    vector<vector<int>> good(5, vector<int>(n + 1));
    vector<int> last(5, 0);

    for (int i = 1; i <= n; i++) {
        for (int k = 0; k < 5; k++) {
            int lst = 0;
            for (int q = k + 1; q < 5; q++) {
                lst = max(lst, last[q]);
            }
            good[k][i] = pre[k][i - 1] - pre[k][lst];
        }

        last[s[i] - 'A'] = i;
    }

    int mx = cur;
    for (int i = 1; i <= n; i ++) {
        int x = s[i] - 'A';
        
        vector <int> t (6);
        for (int j = 4; j >= 0; j --) {
            t[j] = t[j + 1] + (pre[j][n] - pre[j][i]);    
        }

        for (int j = 0; j < 5; j ++) {
            if (j == x) continue;

            int now = cur + (-1 * ok[i] * v[x]);

            // cerr << "i : " << i << ' ' << j << ' ' << now << '\n'; 

            if (t[j + 1] > 0) now -= v[j];
            else now += v[j];
            
            if (j < x) {
                for (int k = j; k < x; k ++) {
                    if (t[k + 1] == 0)
                        now += 2 * good[k][i] * v[k];
                }
            } else {
                for (int k = x; k < j; k ++) {
                    if (t[k + 1] == 0)
                        now -= 2 * good[k][i] * v[k];
                }
            }

            // cerr << "i : " << i << ' ' << j << ' ' << now << '\n'; 
            mx = max (mx, now);
        }
    }

    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}