#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;

void ovo() {
    int n, k; cin >> n >> k;
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        int x; 
        cin >> x;
        sum += x;
    }

    if ((sum % 2 == 0) && (n * k % 2 != 0)) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}