#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, m; cin >> n >> m;
    bool ok = false;

    auto dfs = [&](int k, auto self) -> void {
        if (k == m) {
            ok = true;
            return;
        }

        if (k % 3 != 0) {
            return;
        } else {
            self (k / 3 * 2, self);
            self (k / 3, self);
        }
    };

    dfs (n, dfs);

    if (ok) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    cin>>_;

    while(_--){
        solve();
    }
    return 0;
}