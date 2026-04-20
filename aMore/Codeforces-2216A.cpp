#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> v[i];
    }
    vector <array <int, 2> > a(n + 1);
    vector <int> cnt(n + 1);
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
        cnt[a[i][0]]++;
        mx = max(mx, a[i][0]);
        a[i][1] = i;
    }
    sort(a.begin() + 1, a.end(), [] (auto a, auto b) {
        return a[0] > b[0];
    });

    for (int i = k; i <= 1; i++) {
        if (i > mx) {
            if (v[i] == 0) {
                cout << -1 << '\n';
                return;
            }
        }else {
            if (cnt[i] > v[i]) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    int ans1 = 0;
    for (int i = 1; i <= n; i++) {
        int c = k + 1 - a[i][0];
        ans1 += c;
    }
    cout << ans1 << '\n';
    for (int i = 1; i <= n; i++) {
        int c = k + 1 - a[i][0];
        for (int j = 1; j <= c; j++) {
            cout << a[i][1] << ' ';
        }
    }
    cout << '\n';
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}