#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int MAXN = 6e7;
const double eps = 1e-12;
const ll mod = 998244353;

void solve ()
{
    ll n, q; cin >> n >> q;
    vector <ll> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    ll t = log2(n);
    vector <vector <ll> > stmx(n + 1, vector <ll> (30));
    vector <vector <ll> > stmn(n + 1, vector <ll> (30));
    for (int i = 1; i <= n; i++) stmx[i][0] = v[i], stmn[i][0] = v[i];
    for (int j = 1; j <= t; j++) {
        for (int i = 1; i <= n - (1LL << j) + 1; i++) {
            stmx[i][j] = max(stmx[i][j - 1], stmx[i + (1LL << (j - 1))][j - 1]);
            stmn[i][j] = min(stmn[i][j - 1], stmn[i + (1LL << (j - 1))][j - 1]);
        }
    }

    while (q--) {
        ll l, r; cin >> l >> r;
        ll len = log2(r - l + 1);
        ll mx = max(stmx[l][len], stmx[r - (1LL << len) + 1][len]);
        ll mn = min(stmn[l][len], stmn[r - (1LL << len) + 1][len]);
        cout << mx - mn << '\n';
    }
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