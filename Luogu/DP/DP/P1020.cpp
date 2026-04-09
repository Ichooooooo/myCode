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
    vector <ll> v;
    v.push_back(0);
    ll t;
    while (cin >> t) {
        v.push_back(t);
    }
    ll n = v.size() - 1;
    
    vector <ll> a(n + 1);
    a[1] = v[1];
    ll ans1 = 1;
    for (int i = 2; i <= n; i++) {
        ll pos = upper_bound(a.begin() + 1, a.begin() + 1 + ans1, v[i], greater<ll>()) - a.begin();
        a[pos] = v[i];
        if (pos > ans1) ans1++;
    }

    vector <ll> b(n + 1);
    b[1] = v[1];
    ll ans2 = 1;
    for (int i = 2; i <= n; i++) {
        ll pos = lower_bound(b.begin() + 1, b.begin() + 1 + ans2, v[i]) - b.begin();
        b[pos] = v[i];
        if (pos > ans2) ans2++;
    }

    cout << ans1 << '\n' << ans2 << '\n';

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