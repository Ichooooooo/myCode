
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;

    vector <int> a (n + 1);
    for (int i = 1; i <=n; i ++) {
        cin >> a[i];
    }

    sort (a.rbegin(), a.rend());

    if (n == 2) {
        cout << a[0] << ' ' << a[1] << '\n';
        return;
    }

    for (int i = 2; i < n; i ++) {
        if (a[i] != a[i - 2] % a[i - 1]) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << a[0] << ' ' << a[1] << '\n';    
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}