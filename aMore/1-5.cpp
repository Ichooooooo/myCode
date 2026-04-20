#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n;
    cin >> n;
    vector <double> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector <int> a(n + 1);
    int c, d;
    while (cin >> c >> d) {
        if (c == 0 && d == 0) {
            break;
        }
        a[c] += d;
    }
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << '\n';
        sum += v[i] * a[i];
    }
    cout << fixed << setprecision(2) << sum << '\n';
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