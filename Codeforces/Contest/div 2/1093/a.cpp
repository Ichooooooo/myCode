#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    
    vector <int> a(n);
    for (int i =0; i < n; i ++) {
        cin >> a[i];
    }

    sort (a.rbegin(), a.rend());
    for (int i = 1; i < n; i ++) {
        if (a[i] == a[i - 1]) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int i = 0; i < n; i ++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}