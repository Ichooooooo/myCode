#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int mod = 1e9 + 7;

int qpow (int a, int b)
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int inv (int x) {
    return qpow (x, mod - 2);
}

void solve ()
{
    
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