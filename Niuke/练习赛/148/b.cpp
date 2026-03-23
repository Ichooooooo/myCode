#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){  
    int n, k; cin >> n >> k;
    int fz = 0, fm = 0;

    vector <int> m (n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> m[i];
        fz += m[i] * i; fm += m[i];
    }

    vector <int> vis(n + 1);
    bool ok = false;
    auto dfs = [&](int a, int cnt, auto self) -> void {
        if (cnt == k) {
            int x = fz, y = fm;
            for (int i = 1; i < a; i ++) {
                if (vis[i]) {x -= i * m[i]; y -= m[i];}
            }
            if (x * fm == y * fz) {
                ok = true;
            } 
            return;
        }

        if (a > n) return;

        vis[a] = true;
        self (a + 1, cnt + 1, self);
        vis[a] = false;
        self (a + 1, cnt, self);
    };

    dfs (1, 0, dfs);

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;a

    while(_--){
        solve();
    }
    return 0;
}