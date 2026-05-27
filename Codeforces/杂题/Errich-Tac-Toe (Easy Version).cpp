
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    
    vector <vector <char>> a (n, vector <char> (n));
    vector <int> c (3);

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
            if (a[i][j] == 'X') {
                c[(i + j) % 3] ++;
            }
        }
    }

    const int INF = 1e10;
    int mn = 0, mm = INF;
    for (int i = 0; i < 3; i ++) {
        if (mm > c[i]) {
            mm = c[i];
            mn = i;
        }
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (a[i][j] != 'X') cout << a[i][j];
            else {
                if ((i + j) % 3 != mn) {
                    cout << a[i][j];
                } else {
                    cout << 'O';
                }
            }
        }

        cout << '\n';
    }
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}