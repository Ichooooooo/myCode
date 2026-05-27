
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> c1 (3), c2 (3);

    vector <vector <char> > a (n, vector <char> (n));
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];

            if (a[i][j] == 'X') {
                c1[(i + j) % 3]++;
            } else if (a[i][j] == 'O') {
                c2[(i + j) % 3]++;
            }
        }
    }

    const int INF = 1e10;
    int mn = INF, mn1 = 0, mn2 = 0;

    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            if (i == j) continue;
            if (mn > (c1[i] + c2[j])) {
                mn = c1[i] + c2[j];
                mn1 = i;
                mn2 = j;
            }
        }
    }

     for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if (a[i][j] == 'X' && (i + j) % 3 == mn1) {
                a[i][j] = 'O';
            } else if (a[i][j] == 'O' && (i + j) % 3 == mn2) {
                a[i][j] = 'X';
            }
        }
    }   

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << a[i][j];
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