#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;
const int N = 55;

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
    return f[n] * g[m] % mod * g[n - m] % mod;
}

void solve(){   
    int n;  cin >> n;
    vector <int> a (n + 1);

    f[0] = 1, g[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }

    for (int i = 0; i <= n; i ++)  cin >> a[i];

    int mx = *max_element (a.begin() + 1, a.end()) ;
    int sum = accumulate (a.begin() + 1, a.end(), 0LL);
    int nmx = count (a.begin() + 1, a.end(), mx);
    int res = (sum - nmx * mx) + a[0] - (mx - 1) * (n - nmx);

    if (res < 0) {
        cout << 0 << endl;
    } else {
        if (res < (n - nmx)) {
            cout << C(n - nmx, res) * f[nmx + res] % mod * f[n - (nmx + res)] % mod << endl;
        } else {
            cout << f[n] % mod << endl;
        }
    }

}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}