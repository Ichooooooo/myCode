#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int len = 2e5;

void ovo() {
    int n; cin >> n;
    vector <arr2> a (n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    vector <vector <vector <int> > >  ss (11, vector <vector <int>> (11, vector <int> (26)));

    int m; cin >> m;
    vector <string> s (m);
    for (int i = 0; i < m; i ++) {
        cin >> s[i];
        int len = s[i].size();
        for (int j = 0; j < len; j ++) {
            // cerr << len << ' ' << s[i][j] << '\n';
            ss[len][j][s[i][j] - 'a'] ++;
            // cerr << len << ' ' << j << ' ' << s[i][j] - 'a' << '\n';
        }
    }

    for (int i = 0; i < m; i ++) {
        int ok = 1;
        if (s[i].size() != n) {
            cout << "No" << '\n';
            continue;
        } 

        for (int j = 0, pos = 0; j < n; j ++, pos++) {
            auto [x, y] = a[j];
            y--;

            if (ss[x][y][(s[i][pos] - 'a')] == 0) {

                // cerr << "nope : " << x << ' ' << y << ' ' << s[i][pos] << '\n';
                ok = 0;
                break;
            }   
        }        

        if (ok) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}