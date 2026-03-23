
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

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

void ovo(){   
    int n, k;  cin >> n >> k;
    cout << qpow (2 * k + 1, n, mod) << '\n';
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while(_--)  ovo();  return 0;
}