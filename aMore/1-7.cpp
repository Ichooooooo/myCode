#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n = 9;
    vector <vector <int> > v(n + 1, vector <int> (n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        map <int, int> mp1;
        for (int j = 1; j <= n; j++) {
            if (v[i][j] > 9 || v[i][j] < 1) {
                cout << 0 << '\n';
                return;
            }
            if (mp1[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp1[v[i][j]] = true;
        }
    }

    for (int j = 1; j <= n; j++) {
        map <int, int> mp1;
        for (int i = 1; i <= n; i++) {
            if (mp1[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp1[v[i][j]] = true;
        }
    }

    map <int, int> mp;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (mp[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp[v[i][j]] = true;
        }
    }
    mp.clear();

    for (int i = 4; i <= 6; i++) {
        for (int j = 1; j <= 3; j++) {
            if (mp[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp[v[i][j]] = true;
        }
    }
    mp.clear();

    for (int i = 7; i <= 9; i++) {
        for (int j = 1; j <= 3; j++) {
            if (mp[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp[v[i][j]] = true;
        }
    }
    mp.clear();

    for (int i = 7; i <= 9; i++) {
        for (int j = 1; j <= 3; j++) {
            if (mp[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp[v[i][j]] = true;
        }
    }
    mp.clear();

    for (int i = 1; i <= 3; i++) {
        for (int j = 4; j <= 6; j++) {
            if (mp[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp[v[i][j]] = true;
        }
    }
    mp.clear();

    for (int i = 4; i <= 6; i++) {
        for (int j = 4; j <= 6; j++) {
            if (mp[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp[v[i][j]] = true;
        }
    }
    mp.clear();

    for (int i = 7; i <= 9; i++) {
        for (int j = 4; j <= 6; j++) {
            if (mp[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp[v[i][j]] = true;
        }
    }
    mp.clear();

    for (int i = 1; i <= 3; i++) {
        for (int j = 7; j <= 9; j++) {
            if (mp[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp[v[i][j]] = true;
        }
    }
    mp.clear();

    for (int i = 4; i <= 6; i++) {
        for (int j = 7; j <= 9; j++) {
            if (mp[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp[v[i][j]] = true;
        }
    }
    mp.clear();

    for (int i = 7; i <= 9; i++) {
        for (int j = 7; j <= 9; j++) {
            if (mp[v[i][j]]) {
                cout << 0 << '\n';
                return;
            }
            mp[v[i][j]] = true;
        }
    }
    mp.clear();

    cout << 1 << '\n';
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}