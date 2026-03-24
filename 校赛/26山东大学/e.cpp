
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, m;
    cin >> n >> m;
    
    int nm = (n + m) / 2;

    int n1 = min (nm, n), n0 = max (0LL, nm - n1);
    for (int i = 1; i <= n1; i ++) cout << 1;
    for (int i = n + 1; i <= nm; i ++) cout << 0;
     
    cout << ' ';
    for (int i = 1; i <= m - n0; i ++) cout << 0;
    for (int i = m - n0 + 1; i <= nm; i ++) cout << 1;

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}