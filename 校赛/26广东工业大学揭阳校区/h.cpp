
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

int qpow (int a, int b, int m)//a的b次方
{
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void ovo() {
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}