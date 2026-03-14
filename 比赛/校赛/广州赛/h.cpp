#include <bits/stdc++.h>
using namespace std;
const char el = '\n';
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(15);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto& v : a) cin >> v;
  vector dp(n + 2, vector<ll>(2));
  for (int i = 1; i <= n; i++) {
    if (i > 1) dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + a[i - 1];
    dp[i][0] = dp[i - 1][1] + a[i - 1];
  }
  cout << max(dp[n][0], dp[n][1]) << el;
  return 0;
}