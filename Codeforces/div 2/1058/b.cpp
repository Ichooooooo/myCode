
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    vector <int> b (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    vector <int> ans (n + 1);
    int now = 1;
    for (int i = 1; i <= n; i ++) {
        if (i == 1) {
            ans[i] = now;
            now ++;
            continue;
        }

        if (b[i] - b[i - 1] == i) {
            ans[i] = now;
            now ++;
        } else {
            ans[i] = ans[i - (b[i] - b[i - 1])];
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}