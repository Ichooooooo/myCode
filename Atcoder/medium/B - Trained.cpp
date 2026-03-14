#include<bits/stdc++.h>
#define int long long
using ll = long long;
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> vis(n + 1, 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    ll cnt = 1, p = a[1];
    for (int i = 1; i <= n; i ++) {
        if (p == 2) {
            cout << cnt << endl;
            return;
        } else {
            if (vis[p]) {
                vis[p] = 0;
                p = a[p];
                cnt ++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int _=1;
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}