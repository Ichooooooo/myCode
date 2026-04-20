#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n; cin >> n;



    int s0 = 0, s1 = 0;
    for (int i = 0; i < n; i ++) {
        int x; cin >> x;
        if (i & 1) {
            s0 += x;
        } else {
            s1 += x;
        }
    }

    if (n == 1) {
        cout << "YES" << '\n';
        return;
    }

    int n0 = n / 2, n1 = (n + 1) / 2;
    
    if (s0 % n0 == 0 && s1 % n1 == 0 && (s0 / n0 == s1 / n1)) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}