
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int x; cin >> x;
    
    int cnt = 0 , y = x, ans = 0;
    while (y) {
        cnt++;
        y /= 10;
    }

    ans = pow (10, cnt) + 1;
    cout << ans << '\n';
    // cout << ans * x << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}