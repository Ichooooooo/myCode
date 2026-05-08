
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;
using i128 = __int128;

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

void ovo() {
    int n; cin >> n;
    
    if (n <= 1) {
        cout << 0 << '\n'; 
    } else if (n == 2) {
        cout << 1 << '\n';
    } else {
        int ans = (((i128)n * (i128)(n - 1)) % mod) * qpow (2, n - 3) % mod;
        cout << ans << '\n';        
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}