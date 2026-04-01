
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 676767677;

void ovo() {    
    int x, y;
    cin >> x >> y;

    int n = x + y;
    int sum = x - y;

    int ans = 0;

    if (sum == 0) { 
        cout << 1 << '\n';
        for (int i = 1; i <= x; i ++) cout << 1 << ' ';
        for (int i = 1; i <= y; i ++) cout << -1 << ' ';
        cout << '\n';        
        return;
    }
    
    int tsm = abs(sum);
    for (int i = 1; i * i <= tsm; i ++) {
        if (tsm % i == 0) {
            if (i * i == tsm) ans ++;
            else ans += 2;
        }
    }

    cout << ans % mod << '\n';
    for (int i = 1; i <= x; i ++) cout << 1 << ' ';
    for (int i = 1; i <= y; i ++) cout << -1 << ' ';
    cout << '\n';

    
} 

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}