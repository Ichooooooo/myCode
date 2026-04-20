#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, m;
    cin >> n >> m;
    vector <int> v(m + 1);
    int sum = 0;
    for (int i = 1; i <= m; i++) {
        cin >> v[i];
        sum += v[i];
    }
    int t = n * (m - 1);
    cout << max(0, sum - t) << '\n';
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