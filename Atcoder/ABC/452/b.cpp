#include <bits/stdc++.h>
#define int long long
using namespace std;

void ovo() {
    int n, m;
    cin >> n >>m;
    
    for (int i = 1; i <= n;i ++) {
        for (int j = 1; j <= m; j ++) {
            if (i == 1 || j == 1 || i == n || j == m) cout << "#";
            else cout << ".";
        }

        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}