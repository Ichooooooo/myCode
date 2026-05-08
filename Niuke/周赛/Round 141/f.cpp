
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n, q;
    cin >> n >> q;

    string s; cin >> s;

    vector <vector <int> > a (26);
    vector <vector <int> > pa (26, vector <int> (n));
    for (int i = 0; i < n; i ++) {
        a[s[i] - 'a'].push_back (i);
        pa[s[i] - 'a'][i] = i;
    }

    vector <vector <int> > b (26, vector <int> (n));

    for (int i = 0; i < 26; i ++) {
        for (int j = 1; j < n; j ++) {
            pa[i][j] = pa[i][j - 1] + pa[i][j];
        }    
    }

    for (int i = 0; i < 26; i ++) {
        if (a[i].empty()) continue;
        if (a[i].size() < 2) continue;

        int pre = a[i][0];
        for (int j = 1; j < a[i].size(); j ++) {
            int p = a[i][j];
            b[i][p] = j * p - pre - j;

            pre += p;
        }

        for (int j = 1; j < n; j ++) {
            b[i][j] = b[i][j - 1] + b[i][j];
        }   
    } 

    while (q --) {
        int l, r, x;
        cin >> l >> r >> x;

        l --; r --;
        if (x == 1) {
            cout << r - l + 1 << '\n';
        } else if (x == 2) {
            int ans = 0;
            for (int i = 0; i < 26; i ++) {
                if (a[i].size() < 2) continue;
                
                auto p1 = lower_bound (a[i].begin(), a[i].end(), l) - a[i].begin();
                auto p2 = prev(upper_bound (a[i].begin(), a[i].end(), r)) - a[i].begin();

                int cnt = p2 - p1 + 1;
                ans += cnt * (cnt - 1) / 2;
            }

            cout << ans << '\n';
        } else {
            int ans = 0;
            for (int i = 0; i < 26; i ++) {
                if (a[i].size() < 2) continue;
                
            }

            cout << ans << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}
