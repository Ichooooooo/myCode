#include <bits/stdc++.h>
#define int long long
using namespace std;

void ovo() {
    int n; cin >> n;
    
    vector <int> pr; pr.reserve (n + 10);
    int cnt = 0;
    for (int i = 1; ; i ++) {
        int ok = 1;
        for (int j = 2; j * j <= i; j ++) {
            if (i % j == 0) {
                ok = 0;
                break;
            }
        }
        
        if (ok) {
            pr.push_back (i);
            cnt++;
        }

        if (cnt == n + 1) {
            break;
        }
    }

    vector <int> ans (n);
    
    for (int i = 0; i < n; i ++) {
        ans[i] = pr[i] * pr[i + 1];
    }

    // for (int i = 1; i < n; i ++) {
    //     cout << gcd (ans[i], ans[i - 1]);
    // }
    
    for (int i = 0; i < n; i ++) {
        cout << ans[i] << " \n"[i == n - 1];
    }

}

signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _=1;
    cin>>_;

    while (_--) ovo();
}