
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    string n, m, l;
    cin >> n >> m >> l;
    int now = (n.back() - '0') * (m.back() - '0') * (l.back() - '0');
    if (now & 1) {
        cout << "A" << '\n';
    } else {
        cout << "B" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}