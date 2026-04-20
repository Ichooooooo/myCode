#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int a, b;
    cin >> a >> b;
    if (a == 0 || a == 1) {
        if (b == 0) {
            if (a == 1) {
                cout << "dudu\n";
            }else {
                cout << "biii\n";
            }
        }else {
            cout << "-\n";
        }
    }else {
        cout << "-\n";
    }
    if (a == 0 || a == 2) {
        cout << "stop\n";
    }else {
        cout << "move\n";
    }
}

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}