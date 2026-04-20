#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve ()
{
    int a, b;
    cin >> a >> b;
    int mx = -1;
    auto cal = [&] (int x) -> int {
        int res = 1;
        while (x > 0) {
            res *= x % 10;
            x /= 10;
        }
        return res;
    };

    for (int i = a; i <= b; i++) {
        int t = i;
        int cnt = 0;
        while (t > 9) {
            t = cal(t);
            cnt++;
        }
        mx = max(mx, cnt);
    }

    vector <int> ans;
    for (int i = a; i <= b; i++) {
        int t = i;
        int cnt = 0;
        while (t > 9) {
            t = cal(t);
            cnt++;
        }
        if (cnt == mx) {
            ans.push_back(i);
        }   
    }
    cout << mx << '\n';
    for (auto x : ans) {
        cout << x << " \n"[x == ans.back()];
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