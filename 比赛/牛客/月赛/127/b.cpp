#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
const int mod = 998244353;
const double eps = 1e-10;

void solve(){   
    int n, k;
    cin >> n >> k;
    vector<int> vis(k);
    
    int t;
    for (int i = 0; i < n; i ++) {
        cin >> t;
        vis[t % k] ++;
    }
    
    int ok = 1;
    for (int i = 0; i < k; i ++) {
        if (vis[i] & 1) {
            ok = 0;
            break;
        }
    }

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
    // cin>>_;

    while(_--){
        solve();
    }
    return 0;
}