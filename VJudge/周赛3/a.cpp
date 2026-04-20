
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    string a, b;
    cin >> a >> b;
    char x = a[0];
    char y = b[0];
    a[0] = y;
    b[0] = x;

    cout << a << ' ' << b << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}