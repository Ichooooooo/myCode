
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo(){   
    int n, l, r, k;
    cin >> n >> l >> r >> k;

    if (n & 1) {
        cout << l << '\n';
    } else {
        auto qpow = [](int x) -> int {
            int cnt = 0;
            while (x > 1) {
                x >>= 1;
                cnt ++;
            }
            return cnt;
        };
        
        int mn = qpow(l), mx = pow (2, mn + 1);
        // cout << mn << ' ' << mx << '\n';
        if (n == 2) {
            cout << -1 << '\n';
        } else if (mx >= l && mx <= r) {
            if (k > n - 2) cout << mx << '\n';
            else cout << l << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while(_--)  ovo();  return 0;
}