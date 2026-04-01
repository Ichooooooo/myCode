
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n, k;
    cin >> n >> k;

    int mx = 1;
    for (int i = 2; i * i <= n; i ++) {
        if (n % i == 0) {
            mx = i;
        }
    }
    
    int cnt = 0;
    if (mx == 1) {
        cnt = 1;
        int tn = n - 1;
        for (int i = 2; i * i <= tn; i ++) {
            if (tn % i == 0) {
                mx = i;
            }
        }     
        cnt += (mx - 1) * (tn / mx) + (tn / mx - 1) * mx;
    } else {
        cnt = (mx - 1) * (n / mx) + (n / mx - 1) * mx;
    }

    if (k > cnt) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
        
        
    }
    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    // cin>>_;

    while (_--) ovo();
}