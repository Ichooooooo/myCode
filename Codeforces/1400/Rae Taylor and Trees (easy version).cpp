
#include <bits/stdc++.h>
#define int long long
using namespace std;
using arr2 = array <int, 2>;
const int mod = 1e9 + 7;

void ovo() {
    int n; cin >> n;
    vector <int> p (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
    }

    vector <int> pre (n + 1), aft (n + 5);
    
    pre[0] = n + 10;
    for (int i = 1; i <= n; i ++) {
        pre[i] = min (pre[i - 1], p[i]);
    }

    for (int i = n; i >= 1; i --) {
        aft[i] = max (aft[i + 1], p[i]); 
    }

    for (int i = 1; i <= n - 1; i ++) {
        // cerr << pre[i] << ' ' << aft[i] << '\n';
        if (pre[i] >= aft[i + 1]) {
            cout << "No" << '\n'; 
            return;
        }
    }

    cout << "Yes" << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}