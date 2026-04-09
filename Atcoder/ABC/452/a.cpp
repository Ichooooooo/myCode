#include <bits/stdc++.h>
#define int long long
using namespace std;

void ovo() {
    int m, d;
    cin >> m >> d;
    if ((m == 1 && d == 7) || (m == 3 && d == 3) || (m == 5 && d == 5) || (m == 7 && d == 7) || (m == 9 && d == 9)) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}