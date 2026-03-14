#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<ll, ll>;

#define fi first
#define se second

const int N = 1e5;
const double eps = 1e-5;
const ll mod = 1e9 + 7;

bool vis[N];
int primes[N];//1-based
int cnt = 0;

void get_primes (ll n)
{
    for (ll i = 2; i <= n; i++) {
        if (!vis[i]) primes[++cnt] = i;
        for (ll j = 1; j <= cnt && i * primes[j] <= n; j++) {
            vis[i * primes[j]] = 1;
            if (i % primes[j] == 0) break;
        }
    }
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