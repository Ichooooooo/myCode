
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

int primes[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 33, 37};

void ovo() {
    int n; 
    cin >> n;
    
    if (n == 4) {
        cout << 2 << ' ' << 2 << '\n';
    } else if (n == 6) {
        cout << 2 << ' ' << 4 << '\n';
    } else {
        if (n & 1) {
            cout << n / 2 << ' ' << (n + 1) / 2 << '\n';
        } else {
            for (int i = 0; i < 13; i ++) {
                if (n % primes[i] == 0) continue;
                else {
                    cout << primes[i] << ' ' << n - primes[i] << '\n';
                    return;
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}