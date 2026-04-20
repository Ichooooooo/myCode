#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int l, n;
    cin >> l >> n;
    vector <vector <int> > v(n + 1, vector <int> (n + 1));
    int ans = 0;
    
    auto dfs = [&] (auto self, int x, int y) -> void {
        if (x == n && y == n) {
            int suma = 0, sumb = 0;
            for (int i = 1; i <= n - 1; i++) {
                suma += v[x][i];
            }
            for (int i = 1; i <= n - 1; i++) {
                sumb += v[i][x];
            }
            if (suma == sumb && l >= suma) {
                v[n][n] = l - suma;
                ans++;
            }
            return;
        }

        if (y == n) {
            int sum = 0;
            for (int i = 1; i <= n - 1; i++) {
                sum += v[x][i];
            }
            if (sum <= l) {
                v[x][y] = l - sum;
                self(self, x + 1, 1);
            }
            return;
        }

        if (x == n) {
            int sum = 0;
            for (int i = 1; i <= n - 1; i++) {
                sum += v[i][y];
            }
            if (sum <= l) {
                v[x][y] = l - sum;
                self(self, x, y + 1);
            }
            return;
        }

        for (int i = 0; i <= l; i++) {
            v[x][y] = i;
            self(self, x, y + 1);
        }
    };
    dfs(dfs, 1, 1);

    cout << ans << '\n';
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