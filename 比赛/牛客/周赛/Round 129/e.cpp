#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 1e9 + 7;
const double eps = 1e-10;

const int N = 2 * 1e5 + 100;
int f[N], g[N]; 

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

int C (int n, int m)
{
    if (m < 0 || m > n) return 0;

    return f[n] * g[m] % mod * g[n - m] % mod;
}


void solve(){   
    int n;  cin >> n;
    
    f[0] = 1, g[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }
    
    int m = qpow(2LL, n - 1);
    for (int i = 1; i <= n; i ++) {
        cout << m * C(n, i) % mod << ' ';
    }
    cout << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}