
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

void ovo() {
    int n;
    cin >> n;

    vector <int> a (n + 1);
    for (int i = 1; i<= n; i ++) cin >> a[i];
    
    if (n <= 2) {
        for (int i = 1; i <= n; i ++) {
            cout << n << " \n"[i == n];
        }
    } else {
        for (int i = 1; i <= n; i++) {
            cout << 2 << " \n"[i == n];
        }
    }
} 

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}