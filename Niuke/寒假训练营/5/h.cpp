
#include<bits/stdc++.h>
#define int long long
#define debug(x) cerr << #x << ": " << x << '\n';
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n; cin >> n;
    vector <vector <int>> a (n, vector <int>(n)), b (n, vector<int> (n));

    int s1 = 0, s0 = 0, c1 = 0, c0 = 0;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> a[i][j];
            if ((i + j) & 1) {
                s1 += a[i][j];
                c1 ++;
            } else {
                s0 += a[i][j];
                c0 ++;
            }
        }
    }

    if ((s1 + s0) % (c1 + c0) != 0) {
        cout << "No" << '\n';
        return;
    }

    int tar = (s1 + s0) / (c1 + c0);
    int w = (tar & 1);
    if (s1 != tar * c1 || s0 != tar * c0) {
        cout << "No" << '\n';
        return;
    }

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            if ((a[i][j] % 2 + 2) % 2 != w) b[i][j] = 1;
            else  b[i][j] = 0;
        }
    }
    
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n - 1; j ++) {
            if (b[i][j] & 1) {
                b[i][j] ^= 1;
                b[i + 1][j] ^= 1;
                b[i][j + 1] ^= 1;
                b[i + 1][j + 1] ^= 1;
            }
        }
    }

    for (int i = 0; i < n; i ++) {
        if (b[n - 1][i] || b[i][n - 1]) {
            cout << "No" << '\n';
            return;
        }
    }

    cout << "Yes" << '\n';

}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}