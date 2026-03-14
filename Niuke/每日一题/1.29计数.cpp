#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 1000000007;
const double eps = 1e-10;
const int N = 1e7;

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
    for (int i = 1; i <= (n + 1010); i++) {
        f[i] = f[i - 1] * i % mod;
        g[i] = qpow(f[i], mod - 2) % mod;
    }

    vector <int> a (n + 2);
    a[0] = 1000;  a[n + 1] = 1;

    for (int i = 1; i <= n; i ++)  cin >> a[i];
    vector <PII> pi; pi.reserve(n);

    int l;
    for (int i = 1; i <= (n + 1); i ++) {
        bool x = (a[i - 1] != 0);
        bool y = (a[i] != 0);

        if (x && !y)  l = i;
        else if (!x && y) {
            pi.push_back({l, i - 1});
        }
    }

    // for (auto[x, y] : pi)  cout << x << ' ' << y << endl;

    int ans = 1;

    for (auto[x, y] : pi) {
        int fw = a[x - 1] - a[y + 1] + 1;
        // cout << fw << endl;
        int nm = y - x + 1;

        // cout << nm + fw - 1 << ' ' << fw - 1 << endl;
        // cout << C(, ) << endl;
        ans = ans * C(nm + fw - 1, fw - 1) % mod;
    }

    cout << ans << endl;
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