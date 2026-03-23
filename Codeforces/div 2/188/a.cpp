
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n; cin >> n;
    string  s; cin >> s;
    vector <int> vis (n);
    vis[0] = 1;

    int now = 0, ans = 1;
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'L') now --;
        else now ++;
        if (!vis[now]) {
            ans ++;
            vis[now] = 1;
        } else {
            break;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}