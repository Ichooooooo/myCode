#include <bits/stdc++.h>
using namespace std;
const char el = '\n';
typedef long long ll;
const ll mod = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(15);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<ll, ll>> c;
    ll ans = 0;
    while (n--) {
      ll a, b;
      cin >> a >> b;
      if (!a)
        ans = max(ans, b);
      else
        c.push_back({a, b});
    }
    sort(c.begin(), c.end(), [&](auto a, auto b) {
      auto [a1, b1] = a;
      auto [a2, b2] = b;
      if (a2 * b1 + b2 != a1 * b2 + b1) return a2 * b1 + b2 > a1 * b2 + b1;
      if (a1 != a2) return a1 < a2;
      if (b1 != b2) return b1 < b2;
      return false;
    });
    for (auto [a, b] : c) ans = (ans * a + b) % mod;
    cout << ans << el;
  }
  return 0;
}