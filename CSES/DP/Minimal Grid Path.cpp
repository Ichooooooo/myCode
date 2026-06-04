
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    
    vector < vector <char> > a (n + 1, vector <char> (n + 1));

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
        }
    }

    string ans;

    set <arr2> st;
    st.insert ({1, 1});
    ans += a[1][1];

    while (st.size()) {
        char mn = 'Z';

        set <arr2> sst;
        for (auto it = st.begin(); it != st.end(); it ++) {
            auto [x, y] = *it;
            if (x + 1 <= n) {
                mn = min (mn, a[x + 1][y]);
            }

            if (y + 1 <= n) {
                mn = min (mn, a[x][y + 1]);
            }
        }

        for (auto it = st.begin(); it != st.end(); it ++) {
            auto [x, y] = *it;
            if (x + 1 <= n && a[x + 1][y] == mn) {
                sst.insert ({x + 1, y});
            }

            if (y + 1 <= n && a[x][y + 1] == mn) {
                sst.insert ({x, y + 1});
            }
        }        

        st = move (sst);
    }

    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}