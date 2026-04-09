#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n, m;
    cin >> n >> m;
    vector <vector <char> > a (n + 1, vector <char> (m + 1));

    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            if (a[i][j] != '.') {
                cnt++;
            }
        }
    }

    vector <int> ll (n + 1, 1), rr (n + 1, m), pp (m + 1, 1), dd (m + 1, n);
    vector <arr2> ans; ans.reserve (cnt + 10);

    while (cnt != 0) {
        int now = cnt;

        for (int i = 1; i <= n; i ++) {
            int j = ll[i];
            while (j <= m && (a[i][j] == '.' || a[i][j] == 'L')) {
                if (a[i][j] == 'L') {
                    a[i][j] = '.';
                    ans.push_back ({i, j});
                    now--;
                }
                j++;
            }
            ll[i] = j;
        }

        for (int i = 1; i <= n; i ++) {
            int j = rr[i];
            while (j >= 1 && (a[i][j] == '.' || a[i][j] == 'R')) {
                if (a[i][j] == 'R') {
                    a[i][j] = '.';
                    ans.push_back ({i, j});
                    now--;
                }
                j--;
            }

            rr[i] = j;
        }

        for (int i = 1; i <= m;i ++) {
            int j = pp[i];
            while (j <= n && (a[j][i] == 'U' || a[j][i] == '.')) {
                if (a[j][i] == 'U') {
                    a[j][i] = '.';
                    ans.push_back ({j, i});
                    now --;
                }
                j++;
            }

            pp[i] = j;
        }  

        for (int i = 1; i <= m;i ++) {
            int j = dd[i];
            while (j >= 1 && (a[j][i] == 'D' || a[j][i] == '.')) {
                if (a[j][i] == 'D') {
                    a[j][i] = '.';
                    ans.push_back ({j, i});
                    now --;
                }
                j--;
            }

            dd[i] = j;
        }          

        if (now == cnt) {
            cout << -1 << '\n';
            return;
        }

        cnt = now;
    }

    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}